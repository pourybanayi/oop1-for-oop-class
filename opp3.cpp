#include <iostream>  


using namespace std;  


template<typename T>  
// تعریف یک کلاس **قالبی (template)** که می‌تونه با هر نوع داده‌ای (int، float، string و ...) کار کنه.
class parent {
protected:
    virtual T Add(T a, T b) {
        // تابع مجازی (virtual): یعنی می‌تونه در کلاس مشتق‌شده override بشه.
        // ورودی: دو عدد از نوع T، خروجی: حاصل جمعشون.
        return a + b;
    }
};

class child : public parent<int> {
    // کلاس child از کلاس قالبی parent با نوع داده int ارث‌بری می‌کنه.
public:
    int Add(int a, int b) override {
        // تابع Add رو override می‌کنیم تا پیاده‌سازی مخصوص کلاس child داشته باشیم.
        
        int c = parent<int>::Add(5, 10);
        // صدا زدن تابع Add کلاس والد با پارامترهای 5 و 10. چون تابع Add توی والد protected هست،
        // می‌تونیم ازش توی کلاس مشتق‌شده استفاده کنیم.
        // 5 + 10 = 15

        return c + 20;
        // خروجی نهایی = 15 + 20 = 35
    }
};

int main() {
    child obj;
    // ایجاد یک شیء از کلاس child

    cout << obj.Add(1, 2) << endl;
    // اینجا تابع Add کلاس child صدا زده می‌شه با پارامترهای 1 و 2.
    // ولی دقت کن که این پارامترها داخل بدنه تابع استفاده نمی‌شن!
    // خروجی همیشه 35 هست چون فقط 5 و 10 جمع زده شدن و بعدش 20 اضافه شده.
}
