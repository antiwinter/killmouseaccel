//  Created by Christian Höltje on 9/20/11.
//  This is public domain. The code was originally taken from
//  http://forums3.armagetronad.net/viewtopic.php?t=3364

#include <IOKit/hidsystem/IOHIDLib.h>
#include <IOKit/hidsystem/IOHIDParameter.h>
#include <IOKit/hidsystem/event_status_driver.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  // if this ever becomes a scale factor, we set it to one
  int32_t accel = 1, i = 1, old;
  IOByteCount len;

  io_connect_t handle = NXOpenEventStatus();
  if (!handle) {
    fprintf(stderr, "No handle\n");
    return 1;
  }

  CFStringRef type = CFSTR(kIOHIDMouseAccelerationType);
  // if (strcmp(argv[1], "mouse") == 0)
  // else if (strcmp(argv[1], "trackpad") == 0)
  //   type = CFSTR(kIOHIDTrackpadAccelerationType);

  if (argc > 1)
    accel = atoi(argv[1]);

  IOHIDGetParameter(handle, type, sizeof old, &old, &len);
  fprintf(stdout, "... 0x%x >> 0x%x\n", old, accel);

  if (type &&
      IOHIDSetParameter(handle, type, &accel, sizeof accel) != KERN_SUCCESS)
    fprintf(stderr, "failed\n");
  else
    printf("done\n");

  NXCloseEventStatus(handle);
  return 0;
}
