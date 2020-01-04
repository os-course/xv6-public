#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int priority;

  if(argc < 2 ){
      printf(2, "Usage: setpr priority\n" );
      exit();
  }

  priority = atoi ( argv[1] );

  if ( priority < 0 || priority > 100 ) {
      printf(2, "Invalid priority (0-100)!\n" );
      exit();
  }

  set_priority (priority);
  cps();

  exit();
}
