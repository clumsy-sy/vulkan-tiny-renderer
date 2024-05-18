# vulkan-tiny-renderer

## 编译 && 运行

只测试了 `MSVC` 的情况

```shell
$ mkdir build
$ cmake -B ./build .
$ cmake --build ./build --config=Debug
```

```shell
$ build\Debug\Vulkan-demo.exe
```

> !!!
> Cmake 中写了绝对路径，需要自行替换


## 渲染器层次