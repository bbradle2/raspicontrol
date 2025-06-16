template <typename F>
struct Defer
{
    Defer(F f) : f_(f) {}
    ~Defer() { f_(); }
    F f_;
};

template <typename F>
Defer<F> defer(F f)
{
    return Defer<F>(f);
}