#<center>qemu虚拟机</center>

<span id="jump"></span>

[TOC]

##一、神人网站

> ### https://bellard.org



## 二、搞到源码

> ### 从 https://download.qemu.org/ 下载源码。
>
> ###同时源码已经放一份到自己[服务器](./2018-02/qemu-2.11.0.tar.xz)

## 三、编译

> #### 1、通用编译方法
>
> ```shell
> [root@localhost qemu-2.11.0]# tar -xf qemu-2.11.0.tar.xz 
> [root@localhost qemu-2.11.0]# cd qemu-2.11.0/
> [root@localhost qemu-2.11.0]# mkdir build
> [root@localhost qemu-2.11.0]# cd build
> [root@localhost qemu-2.11.0]# ../configure
> [root@localhost qemu-2.11.0]# make
> [root@localhost qemu-2.11.0]# make install
> ```
>
> #### 2、通用编译方法会编译所有支持的架构。时间长，而且空间十分巨大，先用`./configure --help`查看各参数的意义，然后选取合适的参数
>
> ```shell
> Usage: configure [options]
> Options: [defaults in brackets after descriptions]
>
> Standard options:
>   --help                   print this message
>   --prefix=PREFIX          install in PREFIX [/usr/local]
>   --interp-prefix=PREFIX   where to find shared libraries, etc.
>                            use %M for cpu name [/usr/gnemul/qemu-%M]
>   --target-list=LIST       set target list (default: build everything)
>                            Available targets: aarch64-softmmu alpha-softmmu 
>                            arm-softmmu cris-softmmu i386-softmmu lm32-softmmu 
>                            m68k-softmmu microblazeel-softmmu microblaze-softmmu 
>                            mips64el-softmmu mips64-softmmu mipsel-softmmu 
>                            mips-softmmu moxie-softmmu or32-softmmu 
>                            ppc64-softmmu ppcemb-softmmu ppc-softmmu 
>                            s390x-softmmu sh4eb-softmmu sh4-softmmu 
>                            sparc64-softmmu sparc-softmmu tricore-softmmu 
>                            unicore32-softmmu x86_64-softmmu xtensaeb-softmmu 
>                            xtensa-softmmu aarch64-linux-user alpha-linux-user 
>                            armeb-linux-user arm-linux-user cris-linux-user 
>                            i386-linux-user m68k-linux-user 
>                            microblazeel-linux-user microblaze-linux-user 
>                            mips64el-linux-user mips64-linux-user 
>                            mipsel-linux-user mips-linux-user 
>                            mipsn32el-linux-user mipsn32-linux-user 
>                            or32-linux-user ppc64abi32-linux-user 
>                            ppc64le-linux-user ppc64-linux-user ppc-linux-user 
>                            s390x-linux-user sh4eb-linux-user sh4-linux-user 
>                            sparc32plus-linux-user sparc64-linux-user 
>                            sparc-linux-user tilegx-linux-user 
>                            unicore32-linux-user x86_64-linux-user
>
> Advanced options (experts only):
>   --source-path=PATH       path of source code [/home/kylin/下载/qemu-2.6.0]
>   --cross-prefix=PREFIX    use PREFIX for compile tools []
>   --cc=CC                  use C compiler CC [cc]
>   --iasl=IASL              use ACPI compiler IASL [iasl]
>   --host-cc=CC             use C compiler CC [cc] for code run at
>                            build time
>   --cxx=CXX                use C++ compiler CXX [c++]
>   --objcc=OBJCC            use Objective-C compiler OBJCC [cc]
>   --extra-cflags=CFLAGS    append extra C compiler flags QEMU_CFLAGS
>   --extra-ldflags=LDFLAGS  append extra linker flags LDFLAGS
>   --make=MAKE              use specified make [make]
>   --install=INSTALL        use specified install [install]
>   --python=PYTHON          use specified python [python -B]
>   --smbd=SMBD              use specified smbd [/usr/sbin/smbd]
>   --static                 enable static build [no]
>   --mandir=PATH            install man pages in PATH
>   --datadir=PATH           install firmware in PATH/qemu
>   --docdir=PATH            install documentation in PATH/qemu
>   --bindir=PATH            install binaries in PATH
>   --libdir=PATH            install libraries in PATH
>   --sysconfdir=PATH        install config in PATH/qemu
>   --localstatedir=PATH     install local state in PATH (set at runtime on win32)
>   --with-confsuffix=SUFFIX suffix for QEMU data inside datadir/libdir/sysconfdir [/qemu]
>   --enable-debug           enable common debug build options
>   --disable-strip          disable stripping binaries
>   --disable-werror         disable compilation abort on warning
>   --disable-stack-protector disable compiler-provided stack protection
>   --audio-drv-list=LIST    set audio drivers list:
>                            Available drivers: oss alsa sdl pa
>   --block-drv-whitelist=L  Same as --block-drv-rw-whitelist=L
>   --block-drv-rw-whitelist=L
>                            set block driver read-write whitelist
>                            (affects only QEMU, not qemu-img)
>   --block-drv-ro-whitelist=L
>                            set block driver read-only whitelist
>                            (affects only QEMU, not qemu-img)
>   --enable-trace-backends=B Set trace backend
>                            Available backends: nop, dtrace, ftrace, log, simple, ust
>   --with-trace-file=NAME   Full PATH,NAME of file to store traces
>                            Default:trace-<pid>
>   --disable-slirp          disable SLIRP userspace network connectivity
>   --enable-tcg-interpreter enable TCG with bytecode interpreter (TCI)
>   --oss-lib                path to OSS library
>   --cpu=CPU                Build for host CPU [x86_64]
>   --with-coroutine=BACKEND coroutine backend. Supported options:
>                            gthread, ucontext, sigaltstack, windows
>   --enable-gcov            enable test coverage analysis with gcov
>   --gcov=GCOV              use specified gcov [gcov]
>   --disable-blobs          disable installing provided firmware blobs
>   --with-vss-sdk=SDK-path  enable Windows VSS support in QEMU Guest Agent
>   --with-win-sdk=SDK-path  path to Windows Platform SDK (to build VSS .tlb)
>
> Optional features, enabled with --enable-FEATURE and
> disabled with --disable-FEATURE, default is enabled if available:
>
>   system          all system emulation targets
>   user            supported user emulation targets
>   linux-user      all linux usermode emulation targets
>   bsd-user        all BSD usermode emulation targets
>   docs            build documentation
>   guest-agent     build the QEMU Guest Agent
>   guest-agent-msi build guest agent Windows MSI installation package
>   pie             Position Independent Executables
>   modules         modules support
>   debug-tcg       TCG debugging (default is disabled)
>   debug-info      debugging information
>   sparse          sparse checker
>
>   gnutls          GNUTLS cryptography support
>   nettle          nettle cryptography support
>   gcrypt          libgcrypt cryptography support
>   sdl             SDL UI
>   --with-sdlabi     select preferred SDL ABI 1.2 or 2.0
>   gtk             gtk UI
>   --with-gtkabi     select preferred GTK ABI 2.0 or 3.0
>   vte             vte support for the gtk UI
>   curses          curses UI
>   vnc             VNC UI support
>   vnc-sasl        SASL encryption for VNC server
>   vnc-jpeg        JPEG lossy compression for VNC server
>   vnc-png         PNG compression for VNC server
>   cocoa           Cocoa UI (Mac OS X only)
>   virtfs          VirtFS
>   xen             xen backend driver support
>   xen-pci-passthrough
>   brlapi          BrlAPI (Braile)
>   curl            curl connectivity
>   fdt             fdt device tree
>   bluez           bluez stack connectivity
>   kvm             KVM acceleration support
>   rdma            RDMA-based migration support
>   uuid            uuid support
>   vde             support for vde network
>   netmap          support for netmap network
>   linux-aio       Linux AIO support
>   cap-ng          libcap-ng support
>   attr            attr and xattr support
>   vhost-net       vhost-net acceleration support
>   spice           spice
>   rbd             rados block device (rbd)
>   libiscsi        iscsi support
>   libnfs          nfs support
>   smartcard       smartcard support (libcacard)
>   libusb          libusb (for usb passthrough)
>   usb-redir       usb network redirection support
>   lzo             support of lzo compression library
>   snappy          support of snappy compression library
>   bzip2           support of bzip2 compression library
>                   (for reading bzip2-compressed dmg images)
>   seccomp         seccomp support
>   coroutine-pool  coroutine freelist (better performance)
>   glusterfs       GlusterFS backend
>   archipelago     Archipelago backend
>   tpm             TPM support
>   libssh2         ssh block device support
>   vhdx            support for the Microsoft VHDX image format
>   numa            libnuma support
>   tcmalloc        tcmalloc support
>   jemalloc        jemalloc support
> ```
>
> 然后调整编译选项
>
> ```shell
> # ./configure --target-list=x86_64-softmmu --enable-debug --enable-kvm --enable-vnc 
> # make -j8
> # make install
> [root@localhost build]# make install
> mkdir -p dtc/libfdt
> mkdir -p dtc/tests
> make[1]: `/packages/qemu-2.11.0/build/capstone/libcapstone.a' is up to date.
> install -d -m 0755 "/usr/local/share/doc/qemu"
> install -c -m 0644 qemu-doc.html "/usr/local/share/doc/qemu"
> install -c -m 0644 qemu-doc.txt "/usr/local/share/doc/qemu"
> install -c -m 0644 docs/interop/qemu-qmp-ref.html "/usr/local/share/doc/qemu"
> install -c -m 0644 docs/interop/qemu-qmp-ref.txt "/usr/local/share/doc/qemu"
> install -d -m 0755 "/usr/local/share/man/man1"
> install -c -m 0644 qemu.1 "/usr/local/share/man/man1"
> install -d -m 0755 "/usr/local/share/man/man7"
> install -c -m 0644 docs/interop/qemu-qmp-ref.7 "/usr/local/share/man/man7"
> install -c -m 0644 docs/qemu-block-drivers.7 "/usr/local/share/man/man7"
> install -c -m 0644 qemu-img.1 "/usr/local/share/man/man1"
> install -d -m 0755 "/usr/local/share/man/man8"
> install -c -m 0644 qemu-nbd.8 "/usr/local/share/man/man8"
> install -c -m 0644 qemu-ga.8 "/usr/local/share/man/man8"
> install -c -m 0644 docs/interop/qemu-ga-ref.html "/usr/local/share/doc/qemu"
> install -c -m 0644 docs/interop/qemu-ga-ref.txt "/usr/local/share/doc/qemu"
> install -c -m 0644 docs/interop/qemu-ga-ref.7 "/usr/local/share/man/man7"
> install -d -m 0755 "/usr/local/share/man/man1"
> install -c -m 0644 fsdev/virtfs-proxy-helper.1 "/usr/local/share/man/man1"
> install -d -m 0755 "/usr/local/share/qemu"
> install -d -m 0755 "/usr/local/var"/run
> install -d -m 0755 "/usr/local/bin"
> install -c -m 0755 qemu-ga ivshmem-client ivshmem-server qemu-nbd qemu-img qemu-io  fsdev/virtfs-proxy-helper scsi/qemu-pr-helper "/usr/local/bin"
> install -d -m 0755 "/usr/local/libexec"
> install -c -m 0755 qemu-bridge-helper "/usr/local/libexec"
> set -e; for x in bios.bin bios-256k.bin sgabios.bin vgabios.bin vgabios-cirrus.bin vgabios-stdvga.bin vgabios-vmware.bin vgabios-qxl.bin vgabios-virtio.bin acpi-dsdt.aml ppc_rom.bin openbios-sparc32 openbios-sparc64 openbios-ppc QEMU,tcx.bin QEMU,cgthree.bin pxe-e1000.rom pxe-eepro100.rom pxe-ne2k_pci.rom pxe-pcnet.rom pxe-rtl8139.rom pxe-virtio.rom efi-e1000.rom efi-eepro100.rom efi-ne2k_pci.rom efi-pcnet.rom efi-rtl8139.rom efi-virtio.rom efi-e1000e.rom efi-vmxnet3.rom qemu-icon.bmp qemu_logo_no_text.svg bamboo.dtb petalogix-s3adsp1800.dtb petalogix-ml605.dtb multiboot.bin linuxboot.bin linuxboot_dma.bin kvmvapic.bin s390-ccw.img s390-netboot.img spapr-rtas.bin slof.bin skiboot.lid palcode-clipper u-boot.e500 qemu_vga.ndrv; do \
>         install -c -m 0644 /packages/qemu-2.11.0/pc-bios/$x "/usr/local/share/qemu"; \
> done
> make -C po install
> make[1]: Entering directory `/packages/qemu-2.11.0/build/po'
>   GEN     bg.mo
>   GEN     tr.mo
>   GEN     de_DE.mo
>   GEN     it.mo
>   GEN     hu.mo
>   GEN     zh_CN.mo
>   GEN     fr_FR.mo
> for obj in bg.mo tr.mo de_DE.mo it.mo hu.mo zh_CN.mo fr_FR.mo; do \
>     base=`basename $obj .mo`; \
>     install -d /usr/local/share/locale/$base/LC_MESSAGES; \
>     install -m644 $obj /usr/local/share/locale/$base/LC_MESSAGES/qemu.mo; \
> done
> make[1]: Leaving directory `/packages/qemu-2.11.0/build/po'
> install -d -m 0755 "/usr/local/share/qemu/keymaps"
> set -e; for x in da     en-gb  et  fr     fr-ch  is  lt  modifiers  no  pt-br  sv ar      de     en-us  fi  fr-be  hr     it  lv  nl         pl  ru     th common  de-ch  es     fo  fr-ca  hu     ja  mk  nl-be      pt  sl     tr bepo    cz; do \
>         install -c -m 0644 /packages/qemu-2.11.0/pc-bios/keymaps/$x "/usr/local/share/qemu/keymaps"; \
> done
> install -c -m 0644 /packages/qemu-2.11.0/build/trace-events-all "/usr/local/share/qemu/trace-events-all"
> for d in x86_64-softmmu; do \
> make --no-print-directory BUILD_DIR=/packages/qemu-2.11.0/build TARGET_DIR=$d/ -C $d install || exit 1 ; \
>         done
> install -d -m 0755 "/usr/local/bin"
> install -c -m 0755 qemu-system-x86_64  "/usr/local/bin"
> [root@localhost build]# 
> ```
>
> 完美安装成功



## 四、具体应用实践。应当如何启动，如何安装其它系统





