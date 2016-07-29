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

NOTE: This is necessary for all bindings (except Python) & also for C programming.

This package contains:

- README & license file.
- The Keystone header files (\*.h) for C/C++ programming.
- 32-bit/64-bit DLLs & static libraries for Microsoft Windows 32-bit/64-bit.
- A simple tool (kstool.exe)

<a class="download" href="https://github.com/keystone-engine/keystone/releases/download/{{ post.title }}/keystone-{{ post.title }}-win64.zip" title="Download Win64 Binaries (ZIP)">Win-64</a>

---

### Python module for Windows - Binaries <img src="/images/python.png" height="28" width="28"> <img src="/images/windows.png" height="28" width="28">

<a class="download" href="https://github.com/keystone-engine/keystone/releases/download/{{ post.title }}/keystone-{{ post.title }}-python-win32.msi" title="Download Python module for Python, Win32">Python-32</a>

NOTE: since this installer is self-contain, no need to install the core engine above.

This will install Keystone module into your corresponding Python edition.

<a class="download" href="https://github.com/keystone-engine/keystone/releases/download/{{ post.title }}/keystone-{{ post.title }}-python-win64.msi" title="Download Python module for Python, Win64">Python-64</a>

---

{% endfor %}
