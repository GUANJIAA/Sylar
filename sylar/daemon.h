#pragma once
#ifndef __SYLAR_DAEMON_H__
#define __SYLAR_DAEMON_H__

#include <functional>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "singleton.h"

namespace sylar
{
    struct ProcessInfo
    {
        // 父进程id
        pid_t parent_id;
        // 子进程id
        pid_t main_id;
        uint64_t parent_start_time = 0;
        uint64_t main_start_time = 0;
        uint32_t restart_count = 0;

        std::string toString() const;
    };

    typedef sylar::Singleton<ProcessInfo> ProcessInfoMgr;

    int start_daemon(int argc, char **argv,
                     std::function<int(int argc, char **argv)> main_cb,
                     bool is_daemon);
}

#endif