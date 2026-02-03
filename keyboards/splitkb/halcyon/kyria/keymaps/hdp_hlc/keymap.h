#pragma once

typedef union {
    uint32_t raw;
    struct {
        bool macos : 1;
    };
} user_config_t;
user_config_t user_config;

uint8_t mod_state;
uint8_t one_shot_mod_state;
