#include <common.h>
#include <asm/arch/io.h>
#include <asm/system.h>

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_ACS
//IMPORTANT: following function must be call before the uboot relocation
static void update_ddr_mmu_table(void)
{
	unsigned int ddr_size_ind = readl(CONFIG_DDR_SIZE_IND_ADDR);
	if(ddr_size_ind < 0x80 || ddr_size_ind > 0x800) //legal DDR size: 128MB - 2GB
	{
		printf("Amloigc log : Illegal ACS DDR memory size setting %dMB!\n",ddr_size_ind);
		while(1);
	}

	gd->ram_size = (ddr_size_ind << 20); //unit is 1MB

	int nIndex = 0;
	int nSetting = 0;
	extern ulong __mmu_table;
	volatile unsigned int *pVMMUTable = __mmu_table;
	for(nIndex = 0 ; nIndex < 0xc00;++nIndex)
	{
		if(nIndex< ddr_size_ind)
			nSetting = (nIndex<<20)|(SEC_PROT_RW_RW | SEC_WB);
		else
			nSetting = 0;

		*(pVMMUTable+nIndex) = nSetting;
	}

}
#endif

int dram_init(void)
{

#ifdef CONFIG_ACS
	update_ddr_mmu_table();
#else
	gd->ram_size = PHYS_MEMORY_SIZE;
#endif
	return 0;
}
