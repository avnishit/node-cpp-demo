/* src/main.cpp */
#include <napi.h>

int add(int a, int b) { return a*10+b; }

Napi::Number hello(const Napi::CallbackInfo& info){

  Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    int returnValue = add(first.Int32Value(), second.Int32Value());

   return Napi::Number::New(env, returnValue);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  exports.Set("data", Napi::Function::New(env,hello));
  return exports;
}

NODE_API_MODULE(testaddon, InitAll)
