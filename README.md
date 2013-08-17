##是要关闭内核的HWECC和SOFTECC使用yaffs自己的ECC
###
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
		2.选择yaffs2自己的ECC校验算法。
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
		3.去掉内核的软件ECC校验。
		修改内核\drivers\mtd\nand\S3c_nand.c
		1172:#else
		1173:  nand->ecc.mode = NAND_ECC_NONE;
