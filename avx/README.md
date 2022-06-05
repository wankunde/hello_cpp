# AVX 和 AVX2 指令入门

[Crunching Numbers with AVX and AVX2](https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX)

通过以下命令确认CPU支持的功能。　　

```
$ sysctl -a | grep machdep.cpu.features
machdep.cpu.features: FPU VME DE PSE TSC MSR PAE MCE CX8 APIC SEP MTRR PGE MCA CMOV PAT PSE36 CLFSH DS ACPI MMX FXSR SSE SSE2 SS HTT TM PBE SSE3 PCLMULQDQ DTES64 MON DSCPL VMX EST TM2 SSSE3 FMA CX16 TPR PDCM SSE4.1 SSE4.2 x2APIC MOVBE POPCNT AES PCID XSAVE OSXSAVE SEGLIM64 TSCTMR AVX1.0 RDRAND F16C
```

当然存在SSE，SSE2，SSE4.1，SSE4.2，AVX1.0，但此处没有AVX2。 但是，由于CPU可能支持AVX2，因此以下命令中出现的指令似乎可以通过提供特殊的编译器选项来使用它。　　

```
$ sysctl -a | grep machdep.cpu.leaf7_features
machdep.cpu.leaf7_features: SMEP ERMS RDWRFSGS TSC_THREAD_OFFSET BMI1 AVX2 BMI2 INVPCID SMAP RDSEED ADX IPT SGX FPU_CSDS MPX CLFSOPT
```

可以通过提供一些编译器选项来使用AVX2。 根据[文章](https://www.bu.edu/tech/support/research/software-and-programming/programming/compilers/gcc-compiler-flags/)，gcc可以使用-mavx2选项。



