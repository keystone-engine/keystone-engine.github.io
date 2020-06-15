---
layout: page
title: Keypatch
permalink: /keypatch/
---

Keypatch is [the award winning plugin](https://www.hex-rays.com/contests/2016/index.shtml) of [IDA Pro](https://www.hex-rays.com/products/ida/) for [Keystone Assembler Engine](http://keystone-engine.org).
See [this introduction](/keypatch0) for the motivation behind Keypatch, and [this slides](http://keystone-engine.org/keypatch/Keypatch-slides.pdf) for how it is implemented. A quick [tutorial](/keypatch/tutorial) is also available.

[Keypatch v2.1](https://github.com/keystone-engine/keypatch/archive/2.1.zip) is available from our [Github repo](https://github.com/keystone-engine/keypatch).

This offers 3 tools inside.

- **Patcher** & **Fill Range**: these allow you to type in assembly to directly patch your binary.
- **Search**: this interactive tool let you search for assembly instructions in binary.

Keypatch is confirmed to work on IDA Pro version 6.4, 6.5, 6.6, 6.8, 6.9, 6.95 but should work flawlessly on older versions.
If you find any issues, please [report](http://keystone-engine.org/contact).


--------------------

### 1. Why Keypatch?

Sometimes we want to patch the binary while analyzing it in IDA, but unfortunately the built-in asssembler of IDA Pro is not adequate.

- Only X86 assembler is available. Support for all other architectures is totally missing.
- The X86 assembler is not in a good shape, either: it cannot understand many modern Intel instructions.
- This tool is not friendly and without many options that would make reverser's life easier.

Keypatch was developed to solve the above problems. Thanks to the power of [Keystone](http://keystone-engine.org), our plugin offers some superior features.

- More friendly & easier to use.
- Cross-architecture: support Arm, Arm64 (AArch64/Armv8), Hexagon, Mips, PowerPC, Sparc, SystemZ & X86 (include 16/32/64bit).
- Cross-platform: work everywhere that IDA works, which is on Windows, MacOS, Linux.
- Based on Python, so it is easy to install as no compilation is needed.
- Open source under GPL v2.

Keypatch can be the missing piece in your toolset of reverse engineering.


--------------

### 2. Install

- Follow the steps in the [appendix section](#appendix-install-keystone-for-ida-pro) to install Python binding of [Keystone assembler](http://keystone-engine.org/download).

- Copy file `keypatch.py` to IDA Plugin folder, then restart IDA Pro to use Keypatch.
    - On Windows, the folder is at `C:\Program Files (x86)\IDA 6.9\plugins`
    - On MacOS, the folder is at `/Applications/IDA\ Pro\ 6.9/idaq.app/Contents/MacOS/plugins`
    - On Linux, the folder may be at `/opt/IDA/plugins/`

`NOTE`

- On Windows, if you get an error message from IDA about "fail to load the dynamic library", then your machine may miss the VC++ runtime library. Fix that by downloading & installing it from [Microsoft website](https://www.microsoft.com/en-gb/download/details.aspx?id=40784)
- On other \*nix platforms, the above error message means you do not have 32-bit Keystone installed yet. See [appendix section](#appendix-install-keystone-for-ida-pro) below for more instructions to fix this.


------------

### 3. Usage

- For a quick start, see [this tutorial](/keypatch/tutorial). For a complete description of all of the features of Keypatch, keep reading.
- To patch your binary, press hotkey `CTRL+ALT+K` inside IDA to open **Keypatch Patcher** dialog.
    - The original assembly, encode & instruction size will be displayed in 3 controls at the top part of the form.
    - Choose the syntax, type new assembly instruction in the `Assembly` box (you can use IDA symbols).
    - Keypatch would *automatically* update the encoding in the `Encode` box while you are typing, without waiting for `ENTER` keystroke.
        - Note that you can type IDA symbols, and the raw assembly will be displayed in the `Fixup` control.
    - Press `ENTER` or click `Patch` to overwrite the current instruction with the new code, then *automatically* advance to the the next instruction.
        - Note that when size of the new code is different from the original code, Keypatch can pad until the next instruction boundary with NOPs opcode, so the code flow is intact. Uncheck the choice `NOPs padding until next instruction boundary` if this is undesired.
        - By default, Keypatch appends the modified instruction with the information of the original code (before being patched). Uncheck the choice `Save original instructions in IDA comment` to disable this feature.
    - By default, the modification you made is only recorded in the IDA database. To apply these changes to the original binary (thus overwrite it), choose menu `Edit | Patch program | Apply patches to input file`.

<p align="center">
<img src="/keypatch/keypatch_patcher.png" height="460" />
</p>

- To fill a range of code with an instruction, select the range, then either press hotkey `CTRL+ALT+K`, or choose menu `Edit | Keypatch | Fill Range`.
    - In the `Assembly` box, you can either enter assembly code, or raw hexcode. Some examples of acceptable raw hexcode are `90`, `aa bb`, `0xAA, 0xBB`.
<p align="center">
<img src="/keypatch/keypatch_fillrange.png" height="460" />
</p>

- To revert (undo) the last patching, choose menu `Edit | Keypatch | Undo last patching`.
- To search for assembly instructions (without overwritting binary), open **Keypatch Search** from menu `Edit | Keypatch | Search`.
    - Choose the architecture, address, endian mode & syntax, then type assembly instructions in the `Assembly` box.
    - Keypatch would *automatically* update the encoding in the `Encode` box while you are typing, without waiting for `ENTER` keystroke.
    - When you click `Search` button, Keypatch would look for all the occurences of the instructions, and show the result in a new form.

<p align="center">
<img src="/keypatch/keypatch_search.png" height="400" />
</p>

- To check for new version of Keypatch, choose menu `Edit | Keypatch | Check for update`.
- At any time, you can also access to all the above Keypatch functionalities just by right-click in IDA screen, and choose from the popup menu.

<p align="center">
<img src="/keypatch/keypatch_menupopup.png" height="300" />
</p>



--------------

### 4. Contact

Email keystone.engine@gmail.com for any questions.

For future update of Keypatch, follow our Twitter [@keystone_engine](https://twitter.com/keystone_engine) for announcement.


----

### Appendix. Install Keystone for IDA Pro

IDA Pro's Python is 32-bit itself, so it can only loads 32-bit libraries. For this reason, we have to build & install Keystone 32-bit. Simply install from Pypi, with pip (32-bit), like followings:

{% highlight bash %}
pip install keystone-engine --pre
{% endhighlight %}

Done? Now go back to [section 2](#2-install) & install Keypatch for IDA Pro. Enjoy!
