#include "RenderingPipeline.h"

ActionResult RenderingPipeline::init(HWND const &window) {
    #define load_TGA_tex_check_failed(target, name) if (!load_TGA_texture((target), (name)))\
                                                        return ActionResult::FAILED;
    final_color_buffer_.init(window);
    drawer_.init(window);

    load_TGA_tex_check_failed(texture_diffuse_, "resource/Fieldstone_DM.tga");
    load_TGA_tex_check_failed(texture_specular_, "resource/fieldstone_SM.tga");

    return ActionResult::SUCCEED;
    #undef load_TGA_tex
}
void RenderingPipeline::update_w_h(win_sz client_width, win_sz client_height) {
    final_color_buffer_.update_w_h(client_width, client_height);
}
void RenderingPipeline::draw() {
    fragments_ = DataFragment::test1();
    Color_V3f light_color{ 0.7f, 0.7f, 1.0f };
    fragment_shader_.apply_shader(fragments_,
                                  texture_diffuse_, texture_specular_, light_color,
                                  colored_fragments_);
    final_color_buffer_.clear();
    merger_.merge(colored_fragments_, final_color_buffer_);
    drawer_.draw(final_color_buffer_);
}

ActionResult RenderingPipeline::load_TGA_texture(TextureColorBuffer &img, char const *file_name) {

    FILE* f = nullptr;
    fopen_s(&f, file_name, "rb");
    if (f == nullptr)
        return ActionResult::FAILED;

    tga::StdioFileInterface file(f);
    tga::Decoder decoder(&file);
    tga::Header header;
    if (!decoder.readHeader(header))
        return ActionResult::FAILED;

    tga::Image image;
    image.bytesPerPixel = header.bytesPerPixel();
    image.rowstride = header.width * header.bytesPerPixel();

    std::vector<uint8_t> tga_img(image.rowstride * header.height);
    image.pixels = &tga_img[0];

    if (!decoder.readImage(header, image, nullptr))
        return ActionResult::FAILED;

    // Optional post-process to fix the alpha channel in
    // some TGA files where alpha=0 for all pixels when
    // it shouldn't.
    decoder.postProcessImage(header, image);

    img.resize(header.width, header.height);
    if (header.bytesPerPixel() == 4) {
        memcpy(&img.at(0, 0), &tga_img[0], image.rowstride * header.height);
    } else if (header.bytesPerPixel() == 1) {
        return ActionResult::FAILED;
    } else return ActionResult::FAILED;

    return ActionResult::SUCCEED;
}