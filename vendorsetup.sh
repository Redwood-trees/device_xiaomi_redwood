# Device Repos [1/2]
git clone --depth=1 https://github.com/Redwood-trees/vendor_xiaomi_redwood.git vendor/xiaomi/redwood

git clone --depth=1 https://github.com/Thereache/android_kernel_xiaomi_redwood.git -b su kernel/xiaomi/redwood 

cd kernel/xiaomi/redwood && git submodule init && git submodule update KernelSU && cd ../../../

# camera Repos [2/2]
git clone --depth=1 https://codeberg.org/thepriyanshujangid/proprietary_vendor_xiaomi_camera.git vendor/xiaomi/camera

