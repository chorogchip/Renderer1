#pragma once
#include<cstring>

template<typename T>
class Texture final {
private:
    size_t width_;
    size_t height_;
    size_t size_;
    T* data_;
public:
    Texture();
    explicit Texture(size_t width, size_t height);
    ~Texture();
    Texture(Texture<T> const &);
    Texture &operator=(Texture<T> const &);

    size_t get_width() const { return width_; }
    size_t get_height() const { return height_; }
    size_t get_size() const { return size_; }
    T const *get_data() const { return data_; }
    T *get_data() { return data_; }
    T const &at(size_t x, size_t y) const {
        return data_[y * width_ + x];
    }
    T const &at(float x, float y) const {
        size_t xx{static_cast<size_t>(x * (this->get_width() - 1))};
        size_t yy{static_cast<size_t>(y * (this->get_height() - 1))};
        return data_[yy * width_ + xx];
    }
    T &at(size_t x, size_t y) {
        return const_cast<T &>(static_cast<Texture<T> const &>(*this).at(x, y));
    }
    T &at(float x, float y) {
        return const_cast<T &>(static_cast<Texture<T> const &>(*this).at(x, y));
    }
    void clear() { memset(data_, 0, size_); }
    void clear(T);
    void resize(size_t width, size_t height);
};
template<typename T>
Texture<T>::Texture():
    width_{0U},
    height_{0U},
    size_{0U},
    data_{nullptr}
{}
template<typename T>
Texture<T>::Texture(size_t width, size_t height):
    width_{width},
    height_{height},
    size_{width * height},
    data_{new T[width * height]}
{}
template<typename T>
Texture<T>::~Texture() {
    delete[] data_;
}
template<typename T>
Texture<T>::Texture(Texture<T> const &t):
    width_{t.width_},
    height_{t.height_},
    size_{t.width_ * t.height_},
    data_{new T[t.width_ * t.height_]}
{}
template<typename T>
Texture<T> &Texture<T>::operator=(Texture<T> const &t) {
    this->resize(t.width_, t.height_);
    memcpy(data_, t.data_, sizeof(data_));
    return *this;
}

template<typename T>
void Texture<T>::clear(T t) {
    for (size_t i = 0; i != height_; ++i)
        for (size_t j = 0; j != width_; ++j)
            data_[i * width_ + j] = t;
}
template<typename T>
void Texture<T>::resize(size_t width, size_t height) {
    width_ = width;
    height_ = height;
    size_ = width_ * height_;
    if (data_)
        delete[] data_;
    if (size_ > 0)
        data_ = new T[width * height];
}