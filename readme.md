Node.js v10 开始，新的 N-API 已经稳定，通过这个新的 API，开发者可以很容易编写跨平台、跨版本的 Node.js 扩展，并且无须反复编译。这样有很多好处，因为经常性的，由于编译环境配置不正确或者缺少某些依赖，在安装二进制包时常常会编译失败，尤其是在 Windows 系统中，这种现象经常发生。然而通过 A-API 编写的扩展，基本上只要经过一次编译，就可以运行在所有支持 N-API 的 Node.js 版本中，而无需再次编译。


使用 npm init 来初始化项目，并安装依赖两个必须的依赖：

node-addon-api 将 Node.js N-API 包装为面向对象编程的库
bindings 自动加载 C++ 扩展的工具
然后，我们需要创建两个 npm 命令，打开 package.json 文件，编辑其中的 scripts 属性，添加如下两个命令：

```
{
    "build": "node-gyp build",
    "build:dev": "node-gyp build --debug"
}
```

执行:

```
npm run build
node index
```