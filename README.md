##是要关闭内核的HWECC和SOFTECC使用yaffs自己的ECC
###
		u-boot    : smart210_uboot-v3.0.tar.gz
		 - smart210-uboot.bin
		 
		dnw-linux : https://github.com/changbindu/dnw-linux
		 -
		
		arm-linux-gcc : FriendlyARM-210-DVD-20130801-A/Linux/arm-linux-gcc-4.5.1-v6-vfp-201203.tgz
		 -
		 
		rootfs    : FriendlyARM-210-DVD-20130801-A/Android/linux-3.0.8-20130722.tgz
		 - rootfs_qtopia_qt4.img (裁减过20M左右，原200M测试同样ok)
		 
		kernel    : FriendlyARM-210-DVD-20130801-A/Linux/linux-3.0.8-20130327.tgz               
		 - uImage (开启yaffs ecc)
		 
		 
		附:kernel开启yaffs的ecc校验
		
		    1.去掉S3C NAND Hardware ECC 选项                                   
		    Device Drivers  --->   
		    <*> Memory Technology Device (MTD) support  ---> 
				<*>   NAND Device Support  --->   
				--- NAND Device Support                                          
				│ │    [ ]   Verify NAND page writes                                    │ │  
				│ │    [ ]   Enable chip ids for obsolete ancient NAND devices          │ │  
				│ │    (0xFF108018) Denali NAND size scratch register address           │ │  
				│ │    < >   GPIO NAND Flash driver                                     │ │  
				│ │    <*>   NAND Flash support for S3C SoC                             │ │  
				│ │    []     S3C NAND driver debug                                    │ │  
				│ │    []     S3C NAND Hardware ECC                                    │ │
		
		    2.去掉内核的软件ECC校验。
		    修改内核\drivers\mtd\nand\S3c_nand.c (改NAND_ECC_SOFT -> NAND_ECC_NONE)
			1194                 nand->ecc.mode = NAND_ECC_NONE;
			1195                 printk(KERN_INFO "S3C NAND Driver is using software ECC.\n");
			
		    3.选择yaffs2自己的ECC校验算法。
		        File systems  --->     
		            [*] Miscellaneous filesystems  --->
		                <*>   YAFFS2 file system support                                 │ │  
		                -*-     512 byte / page devices                                  │ │  
		                [ ]       Use older-style on-NAND data format with pageStatus byt│ │  
		                [*]         Lets Yaffs do its own ECC                            │ │  
		                [ ]           Use the same ecc byte order as Steven Hill's nand_e│ │  
		                -*-     2048 byte (or larger) / page devices                     │ │  
		                [*]       Autoselect yaffs2 format 
		    配置好内核以后重新编译内核。
