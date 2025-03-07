#include <iostream>

using namespace std;

class Parent {
private:
    int privateVar = 10;  // فقط از داخل Parent قابل دسترسی است
protected:
    int protectedVar = 20; // در کلاس‌های فرزند (public/protected) قابل دسترسی است
public:
    int publicVar = 30; // در همه‌جا قابل دسترسی است

    int getPrivateVar() { return privateVar; } // تنها راه دسترسی به privateVar
};

// **ارث‌بری عمومی (public)**
class PublicChild : public Parent {
public:
    void modifyData() {
        // privateVar = 50; // ❌ خطا! privateVar قابل دسترسی نیست
        protectedVar = 50; // ✅ قابل تغییر است
        publicVar = 60;    // ✅ قابل تغییر است
    }

    void showData() {
        // cout << privateVar << endl; // ❌ خطا! غیرقابل‌دسترسی
        cout << "Protected: " << protectedVar << endl; // ✅
        cout << "Public: " << publicVar << endl; // ✅
    }
};

// **ارث‌بری محافظت‌شده (protected)**
class ProtectedChild : protected Parent {
public:
    void modifyData() {
        // privateVar = 100; // ❌ خطا!
        protectedVar = 100; // ✅ مجاز
        publicVar = 200;    // ✅ مجاز
    }

    void showData() {
        cout << "Protected: " << protectedVar << endl; // ✅
        cout << "Public: " << publicVar << endl; // ✅
    }
};

// **ارث‌بری خصوصی (private)**
class PrivateChild : private Parent {
public:
    void modifyData() {
        // privateVar = 500; // ❌ خطا!
        protectedVar = 500; // ✅ مجاز
        publicVar = 600;    // ✅ مجاز
    }

    void showData() {
        cout << "Protected: " << protectedVar << endl; // ✅
        cout << "Public: " << publicVar << endl; // ✅
    }
};

int main() {
    PublicChild p;
    p.modifyData();  // ✅ اجرا می‌شود
    p.showData();    // ✅ اجرا می‌شود
    p.publicVar = 100; // ✅ قابل تغییر در بیرون کلاس
    // p.protectedVar = 200; // ❌ خطا! protected است

    ProtectedChild q;
    q.modifyData();  // ✅ اجرا می‌شود
    q.showData();    // ✅ اجرا می‌شود
    // q.publicVar = 300; // ❌ خطا! در ارث‌بری protected، public به protected تبدیل شده است

    PrivateChild r;
    r.modifyData();  // ✅ اجرا می‌شود
    r.showData();    // ✅ اجرا می‌شود
    // r.publicVar = 400; // ❌ خطا! در ارث‌بری private، public به private تبدیل شده است

    return 0;
}
