/*
     Copyright (C) 2024 The LineageOS Project
     SPDX-License-Identifier: Apache-2.0
 */

#include <vector>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;

std::vector<std::string> ro_props_default_source_order = {
    "",
    "bootimage.",
    "odm.",
    "odm_dlkm.",
    "product.",
    "system.",
    "system_ext.",
    "vendor.",
    "vendor_dlkm.",
};

void property_override(char const prop[], char const value[], bool add = true) {
    prop_info *pi;
    pi = (prop_info *) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else if (add)
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void set_ro_build_prop(const std::string &prop, const std::string &value) {
    for (const auto &source : ro_props_default_source_order) {
        auto prop_name = "ro." + source + "build." + prop;
        if (source == "")
            property_override(prop_name.c_str(), value.c_str());
        else
            property_override(prop_name.c_str(), value.c_str(), false);
    }
}

void set_ro_product_prop(const std::string &prop, const std::string &value) {
    for (const auto &source : ro_props_default_source_order) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    }
}

void vendor_load_properties() {
    std::string region;
    std::string sku;
    std::string hwversion;
    region = GetProperty("ro.boot.hwc", "");
    sku = GetProperty("ro.boot.hardware.sku", "");
    hwversion = GetProperty("ro.boot.hwversion", "");

    std::string model;
    std::string brand;
    std::string device;
    std::string fingerprint;
    std::string description;
    std::string marketname;

    if (region == "IN") {
        device = "redwoodin";
        brand = "POCO";
        description = "redwood_global-user 14 UKQ1.240624.001 OS2.0.3.0.UMSMIXM release-keys";
        fingerprint = "POCO/redwoodin/redwoodin:14/UKQ1.240624.001/OS2.0.3.0.UMSMIXM:user/release-keys";
        marketname = "POCO X5 Pro 5G";
        model = "22101320I";
    } else if (region == "GL") {
        device = "redwood";
        brand = "POCO";
        description = "redwood_global-user 14 UKQ1.240624.001 OS2.0.3.0.UMSMIXM release-keys";
        fingerprint = "POCO/redwood_global/redwood:14/UKQ1.240624.001/OS2.0.3.0.UMSMIXM:user/release-keys";
        marketname = "POCO X5 Pro 5G";
        model = "22101320G";
    } else if (region == "CN") {
        device = "redwood";
        brand = "Redmi";
        description = "redwood-user 14 UKQ1.240624.001 OS2.0.3.0.UMSMIXM release-keys";
        fingerprint = "Redmi/redwood/redwood:14/UKQ1.240624.001/OS2.0.3.0.UMSMIXM:user/release-keys";
        marketname = "Redmi Note 12 Pro Speed";
        model = "22101320C";
    }

    set_ro_build_prop("fingerprint", fingerprint);
    set_ro_product_prop("brand", brand);
    set_ro_product_prop("device", device);
    set_ro_product_prop("model", model);
    
    property_override("ro.product.marketname", marketname.c_str());
    property_override("ro.build.description", description.c_str());
}
