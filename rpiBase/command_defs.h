#ifndef COMMAND_DEFS_H
#define COMMAND_DEFS_H

#pragma once

namespace rpi
{
    // command targets ranging from 0x00010000 - 0x0FFF0000 => 4095 possible command senders
    const int CMD_TARGET_MASK = 0xFFFF0000;

    const int CMD_TARGET_BROADCAST = 0x00000000;
    const int CMD_TARGET_MONITOR = 0x00010000;
    const int CMD_TARGET_CONTROLLER = 0x00020000;
    const int CMD_TARGET_MOCKSERVICE = 0x000A0000;

    // command ids ranging from 0x0000 - 0x0FFF => 4095 possible commands
    const int CMD_MASK = 0x0000FFFF;

    const int CMD_STOP = 0x0000;
    const int CMD_RESTART = 0x0001;
    const int CMD_REBOOT = 0x0002;

    const int CMD_GET_BRIGHTNESS = 0x0003;
    const int CMD_GET_MIN_BRIGHTNESS = 0x0004;
    const int CMD_GET_MAX_BRIGHTNESS = 0x0005;
    const int CMD_SET_BRIGHTNESS = 0x0006;
    const int CMD_SET_MIN_BRIGHTNESS = 0x0007;
    const int CMD_SET_MAX_BRIGHTNESS = 0x0008;
    const int CMD_ENABLE_AUTODIMMING = 0x0009;
    const int CMD_DISABLE_AUTODIMMING = 0x000A;

    const int CMD_SEND_PUSH_BUTTON_EDGE = 0x000B;

    const int CMD_GET_TEMPERATURE = 0x000C;
    const int CMD_SET_TEMPERATURE = 0x000D;

    const int CMD_DISABLE_KEEP_ALIVE = 0x0100;
    const int CMD_ENABLE_KEEP_ALIVE = 0x0101;

    // keep alive ranging from 0x1000 - 0x1FFF => 4095 possible keep alive targets
    const int CMD_KEEP_ALIVE = 0x1000;
}

#endif // COMMAND_DEFS_H

