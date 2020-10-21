---
layout: page
title: Download
permalink: /download/
---

{% for post in site.tags.changelog limit:1 %}

The current version is **{{ post.title }}**, which was released on <time datetime="{{ post.date | date: "%Y-%m-%d" }}"> {{ post.date | date: "%B %e, %Y" }}</time>.

See the [version history](/changelog/) for a list of changes.

---

### Git repository <img src="/images/octocat.jpg" height="32" width="32">

The latest version of the source code can be retrieved at our [Git repository](https://github.com/keystone-engine/keystone).

---

### Source archive <img src="/images/tgz.png" height="28" width="28"> <img src="/images/zip.png" height="32" width="32">

<a class="download" href="https://github.com/keystone-engine/keystone/archive/{{ post.title }}.zip" title="Download source (ZIP)">.ZIP</a>

This package contains:

- The complete source code for the Keystone framework.
- Bindings for Python, NodeJS, Ruby, Go, Rust, Haskell & OCaml.
- A simple tool named "kstool" to compile input assembly instructions.
- A sample programs.

This is the recommended version for all platforms.

<a class="download" href="https://github.com/keystone-engine/keystone/archive/{{ post.title }}.tar.gz" title="Download source (TGZ)">.TGZ</a>

---

### Windows - Core engine <img src="/images/windows.png" height="28" width="28">

<a class="download" href="https://github.com/keystone-engine/keystone/releases/download/{{ post.title }}/keystone-{{ post.title }}-win32.zip" title="Download Win32 Binaries (ZIP)">Win-32</a>

NOTE:

- This is necessary for all bindings (except Python) & also for C programming.
- If Keystone reports an error like "fail to load the dynamic library", then you may need to install [Microsoft VC++ runtime library](https://www.microsoft.com/en-gb/download/details.aspx?id=40784)

This package contains:

- README & license file.
- The Keystone header files (\*.h) for C/C++ programming.
- 32-bit/64-bit DLLs & static libraries for Microsoft Windows 32-bit/64-bit.
- A simple tool (kstool.exe)

<a class="download" href="https://github.com/keystone-engine/keystone/releases/download/{{ post.title }}/keystone-{{ post.title }}-win64.zip" title="Download Win64 Binaries (ZIP)">Win-64</a>

---

### Python module for Windows/MacOS/Linux - Binaries <img src="/images/python.png" height="28" width="28">

With `pip` (or `pip3` for Python 3 users), you can easily install Python module for either Windows, MacOS or Linux.

{% highlight bash %}
pip install keystone-engine
{% endhighlight %}

In case you wish to upgrade from older version of Keystone, do:

{% highlight bash %}
pip install keystone-engine --upgrade
{% endhighlight %}

Remember to stick "sudo" in front for root privilege if needed.


---

{% endfor %}
