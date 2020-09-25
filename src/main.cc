#include <napi.h>

using namespace Napi;

Value hello(const CallbackInfo &info) {
  Env env = info.Env();

  if (!info[0].IsString()) {
    TypeError::New(env, "the argument passed to hello() must be a string")
      .ThrowAsJavaScriptException();

    return env.Null();
  }

  return String::New(env, "Hello, " + info[0].As<String>().Utf8Value());
}

Object Init(Env env, Object exports) {  
  exports.Set("hello", Function::New(env, hello, "hello"));

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)