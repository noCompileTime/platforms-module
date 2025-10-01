#include "platform_monitor.hpp"

namespace windows
{
    auto PlatformMonitor::init() -> void
    {
            const auto monitor = MonitorFromWindow(nullptr, MONITOR_DEFAULTTOPRIMARY);

         MONITORINFOEX monitor_info { };
                       monitor_info.cbSize = sizeof(MONITORINFOEX);

        GetMonitorInfo(monitor, &monitor_info);

              width  = monitor_info.rcMonitor.right  - monitor_info.rcMonitor.left;
              height = monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top;
    }
}