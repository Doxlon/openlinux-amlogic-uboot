ddwin32 --list
ddwin32 of=temp.bin if=\\?\Device\Harddisk2\Partition0 count=1

ddwin32 if=%1 of=t.bin	bs=1 count=442
ddwin32 of=t.bin if=temp.bin  bs=1 skip=442 seek=442 
dir t.bin
copy t.bin j.bin
ddwin32 of=t.bin if=%1   bs=512 skip=1 seek=1

ddwin32 if=/dev/zero of=t.bin  bs=512 seek=1023 count=1
ddwin32 if=t.bin of=\\?\Device\Harddisk2\Partition0 
sync