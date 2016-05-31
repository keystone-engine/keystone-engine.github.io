---
layout: page
title: Documentation
permalink: /docs/
---

Find here how to compile/install/program Keystone & other docs.

---

## Compile & install Keystone

### 1. From source code

Find the source in [Download](/download) section and follow the instructions in [COMPILE.md](https://github.com/keystone-engine/keystone/blob/master/docs/COMPILE.md) to build and install the core of Keystone.

### 2. Precompiled binaries <img src="/images/windows.png" height="24" width="24"> <img src="/images/python.png" height="24" width="24">

At the moment precompiled binaries for *Windows* are available in our [Download](/download) section.

If you only want to write your tool in Python on *Windows*, all you need is the *Python installer*, which includes full Keystone module. The Windows core engine is *not necessary* because it is *already embedded inside* the Python module.

For all other the bindings, firstly you still need to install the *Windows core engine*, which also includes the static/dynamic libraries and also the headers (\*.h) for C programming.

### 3. Python binding

To program in Python, you need to install Python binding after you already installed the core in the above step.

NOTE: If you already installed the precompiled Python module from section 2 above, skip this part.

To install Python binding from source on \*nix platforms, do:
{% highlight bash %}
$ cd bindings/python
$ sudo make install
{% endhighlight %}

To install Python binding from source on Windows, do:
{% highlight bash %}
cd bindings/python
python setup.py install
{% endhighlight %}

For Windows, after above steps, you need to copy all the *DLL files* from the *Windows core engine* in the [Download](/download) section into directory *C:\location_to_python\Lib\site-packages\keystone\*.

### 4. Other bindings

To program in other languages (Ruby, NodeJS, Go & Rust), follow the documentation in respective directories under [bindings/\<language\>](https://github.com/keystone-engine/keystone/blob/master/bindings).

---

## Programming

Find in tutorials below how to write your Keystone tools using your favorite programming languages.

- [Quick tutorial on programming with Keystone - with C & Python](tutorial.html).

---

## Miscellaneous

- [Beyond LLVM](/docs/beyond_llvm.html): A quick technical comparison of Keystone and LLVM.
