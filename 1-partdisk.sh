sed -e 's/\s*\([\+0-9a-zA-Z]*\).*/\2/' << FDISK_CMDS  | sudo fdisk $1
o      # create new GPT partition
n      # add new partition
p      # primary partition
1      # partition number
       # default - first sector 
       # default - last sector
t      # change partition type
1      # partition number
0b     # Phat file system
w      # write partition table and exit
FDISK_CMDS