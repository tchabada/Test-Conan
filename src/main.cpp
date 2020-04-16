// #include <folly/executors/GlobalExecutor.h>
// #include <folly/experimental/coro/BlockingWait.h>
// #include <folly/experimental/coro/Task.h>
// #include <folly/futures/Future.h>

// folly::coro::Task<int> task42()
// {
//     co_return 42;
// }

// folly::coro::Task<int> taskSlow43()
// {
//     co_await folly::futures::sleep(std::chrono::seconds{1});
//     co_return co_await task42() + 1;
// }

// int main()
// {
//     auto x = folly::coro::blockingWait(taskSlow43().scheduleOn(folly::getCPUExecutor().get()));

//     return 0;
// }

// #include <folly/FBString.h>
// #include <folly/Format.h>
// #include <folly/Uri.h>
// #include <folly/executors/ThreadedExecutor.h>
// #include <folly/futures/Future.h>
// #include <iostream>
// #include <utility>

// static void print_uri(const folly::fbstring &address)
// {
//     const folly::Uri uri(address);
//     const auto       authority = folly::format("The authority from {} is {}", uri.fbstr(), uri.authority());
//     std::cout << authority << std::endl;
// }

// int main()
// {
//     folly::ThreadedExecutor         executor;
//     folly::Promise<folly::fbstring> promise;
//     folly::Future<folly::fbstring>  future = promise.getSemiFuture().via(&executor);
//     folly::Future<folly::Unit>      unit   = std::move(future).thenValue(print_uri);
//     promise.setValue("https://conan.io/");
//     std::move(unit).get();
//     return 0;
// }

#include <string>

#include "boost_await.h"

boost::future<int> g()
{
    co_return 42;
}

boost::future<std::string> f()
{
    co_return std::to_string(co_await g());
}

int main()
{
    auto s = f().get();
}