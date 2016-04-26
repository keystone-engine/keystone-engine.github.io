---
layout: default
title: Programming with C & Python
---

## Tutorial for Keystone

This short tutorial shows how the Keystone API works. There are more APIs than those used here, but this is all we need to get started.

### 1. Tutorial for C language

The following sample code presents how to compile 32-bit assembly instructions of X86 in C language.

{% highlight c linenos %}
  /* test1.c */
  #include <stdio.h>
  #include <keystone/keystone.h>
  
  // separate assembly instructions by ; or \n
  #define CODE "INC ecx; DEC edx"
  
  int main(int argc, char **argv)
  {
      ks_engine *ks;
      ks_err err;
      size_t count;
      unsigned char *encode;
      size_t size;
  
      err = ks_open(KS_ARCH_X86, KS_MODE_32, &ks);
      if (err != KS_ERR_OK) {
          printf("ERROR: failed on ks_open(), quit\n");
          return -1;
      }
  
      if (ks_asm(ks, CODE, 0, &encode, &size, &count) != KS_ERR_OK) {
          printf("ERROR: ks_asm() failed & count = %lu, error = %u\n",
		         count, ks_errno(ks));
      } else {
          size_t i;
  
          printf("%s = ", CODE);
          for (i = 0; i < size; i++) {
              printf("%02x ", encode[i]);
          }
          printf("\n");
          printf("Compiled: %lu bytes, statements: %lu\n", size, count);
      }
  
      // NOTE: free encode after usage to avoid leaking memory
      ks_free(encode);
  
      // close Keystone instance when done
      ks_close(ks);
  
      return 0;
  }
{% endhighlight %}

<br>
To compile this file, we need a Makefile like below.

{% highlight makefile %}
KEYSTONE_LDFLAGS = -lkeystone -lstdc++ -lm

all:
	${CC} -o test1 test1.c ${KEYSTONE_LDFLAGS}

clean:
	rm -rf *.o test1
{% endhighlight %}


<br>
Readers can get this sample code in a zip file [here](/samples/test1.zip). Compile and run it as follows.

{% highlight bash %}

$ make
cc -o test1 test1.c -lkeystone -lstdc++ -lm

$ ./test1
INC ecx; DEC edx = 41 4a 
Compiled: 2 bytes, statements: 2
{% endhighlight %}

<br>
The C sample is intuitive, but just in case, readers can find below the explanation for each line of *test1.c*.

- Line 3: Include header file **keystone.h** before we do anything.

- Line 6: Assembly string we want to compile. The code in this sample is X86 32bit, in Intel format. You can either separate assembly instructions in this string by ";" or "\n".

- Line 10: Declare a handle variable of the pointer to data type **ks_engine**. This handle will be used for every API of Keystone.

- Line 11: Declare an error variable of the data type **ks_err**. This variable will be used to verify the result returned from all the API.

- Line 12: Declare a variable to contain number of statements this program will compile (line *22*).

- Line 13: Declare *encode*, a pointer variable of the type *unsigned char*, which points to an array containing the encoding of compiled instructions.

- Line 14: Declare *size*, a variable to contain the size (in bytes) of *encode* variable.

- Line 16 ~ 20: Initialize Keystone with function **ks_open**. This API accepts 3 arguments: the hardware architecture, hardware mode and pointer to Keystone handle. In this sample, we want to assemble 32-bit code for X86 architecture. In return, we have the handle updated in variable *ks*. This API can fail in extreme cases, so our sample verifies the returned result against the error code *KS_ERR_OK*.

- Line 22: Compile the input assembly string using the API **ks_asm** with the handle we got from the *ks_open*. The 2nd argument of *ks_asm()* is the assembly string we want to compile. The 3rd argument is the address of the first instruction, which can be ignored in some architectures such as X86. In return, this API gives back a dynamically allocated memory in the next argument *encode*, as well as its size in *size*. Keystone also lets us know how many statements in the input assembly was handled during this process, thus give us a hint where it stops in case the input has error.

- Line 25 ~ 34: Print out instruction encoding of the input assembly returned in the memory array kept in *encode* variable.

- Line 37: Using the API **ks_free()** to free memory kept in variable *encode*, which was allocated by *ks_asm()*.

- Line 40: Close the handle when we are done with the API **ks_close()**.

<br>
By default, Keystone accepts X86 assembly in Intel syntax. Keystone has an API named **ks_option** to customize its engine at run-time. Before running *ks_asm*, we can switch to X86 AT&T syntax by calling *ks_option* like below.

{% highlight c %}
    ks_option(ks, KS_OPT_SYNTAX, KS_OPT_SYNTAX_ATT);
{% endhighlight %}

<br>
Sample code [test2.c](/samples/test1.zip) demonstrates X86 AT&T support.

---

### 2. Tutorial for Python language

The following code presents the same example as above, but in Python, to compile 32-bit assembly code of X86.

{% highlight python linenos %}
 from keystone import *

 # separate assembly instructions by ; or \n
 CODE = "INC ecx; DEC edx"
 
 try:
   # Initialize engine in X86-32bit mode
   ks = Ks(KS_ARCH_X86, KS_MODE_32)
   encoding, count = ks.asm(CODE)
   print("%s = %s (number of statements: %u)" %(CODE, encoding, count))
 except KsError as e:
   print("ERROR: %s" %e)
{% endhighlight %}

<br>
Readers can get this sample code [here](/samples/test1.py). Run it with Python as follows.

{% highlight bash %}
$ ./test1.py
INC ecx; DEC edx = [65, 74] (number of statements: 2)
{% endhighlight %}

<br>
This Python sample is intuitive, but just in case, readers can find below the explanation for each line of *test1.py*.

- Line 1: Import Keystone module before using it.

- Line 4: Assembly string we want to compile. The code in this sample is X86 32bit, in Intel format. You can either separate assembly instructions in this string by ";" or "\n".

- Line 8: Initialize Keystone with class **Ks**. This class accepts 2 arguments: the hardware architecture and hardware mode. This sample deals with 32-bit code for X86 architecture. In return, we have a variable of this class in *ks*.

- Line 9: Compile assembly instruction using method **asm**. In return, we have a list of encoding bytes, and number of input statements that Keystone handled during compilation process, which gives us a hint where it stops in case the input has error. 

- Line 10: Print out the instruction encoding and number of assembly statements processed.

- Line 11 ~ 12: handle exception in the type of **KsError**, which is triggered when something is wrong.

<br>
By default, Keystone accepts X86 assembly in Intel syntax. To handle X86 AT&T syntax, we can simply switch to syntax AT&T like below.

{% highlight c %}
   ks = Ks(KS_ARCH_X86, KS_MODE_32)
   ks.syntax = KS_OPT_SYNTAX_ATT
{% endhighlight %}

<br>
Sample code [test2.py](/samples/test2.py) demonstrates X86 AT&T support.

---

### 3. More examples

This tutorial does not explain all the API of Keystone yet.

- For C sample, see code in directory [samples/](https://github.com/keystone-engine/keystone/tree/master/samples) in Keystone source.

- For Python sample, see code in directory [bindings/python/](https://github.com/keystone-engine/keystone/tree/master/bindings/python) in Keystone source.

