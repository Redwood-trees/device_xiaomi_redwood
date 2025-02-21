color="\033[1;36m"
end="\033[0m"
# Common DT
echo -e "${color}Cloning Common DT${end}"
git clone https://github.com/Redwood-trees/device_xiaomi_sm8350-common device/xiaomi/sm8350-common
# Vendor & Kernel Sources
echo -e "${color}Cloning vendor${end}"
git clone https://github.com/Redwood-trees/vendor_xiaomi_redwood vendor/xiaomi/redwood
git clone https://github.com/Redwood-trees/vendor_xiaomi_sm8350-common vendor/xiaomi/sm8350-common
echo -e "${color}Cloning kernel${end}"
git clone https://github.com/Thereache/android_kernel_xiaomi_redwood kernel/xiaomi/sm8350
sleep 1
# Hardware Sources
echo -e "${color}Cloning Hardware & Timekeep ${end}"
rm -rf hardware/xiaomi
git clone https://github.com/Thereache/android_hardware_xiaomi hardware/xiaomi 
# Miui Camera
echo -e "${color}Cloning Miui Camera${end}"
git clone https://github.com/Redwood-trees/vendor_xiaomi_redwood-miuicamera vendor/xiaomi/redwood-miuicamera
sleep 1
