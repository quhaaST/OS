fallocate -l 50M lofs.img
sudo losetup -f lofs.img 
losetup -a
sudo mkfs.ext4 -dev -loop14
sudo mkfs.ext4 /dev/loop14
mkdir lofsdisk
sudo mount /dev/loop14 ~/week11/lofsdisk
