#ifndef MODULES_CONFIG_H
#define MODULES_CONFIG_H

// MODULES
// - PIR sensor
// connected to ANALOG DEBUG HEADER through T2 (RB9)
#define MODULES_CONFIG_PIR_TRIS TRISBbits.TRISB9
#define MODULES_CONFIG_PIR_ANSEL ANSELBbits.ANSB9
#define MODULES_CONFIG_PIR_PORT PORTBbits.RB9

#endif

// print compile time error when 
#ifndef MODULES_CONFIG_H
#error "modules_config.h MODULES_CONFIG_H missing file or declaration"
#endif

#ifndef MODULES_CONFIG_PIR_TRIS
#error "modules_config.h MODULES_CONFIG_PIR_TRIS missing TRIS pin config"
#endif
#ifndef MODULES_CONFIG_PIR_ANSEL
#error "modules_config.h MODULES_CONFIG_PIR_ANSEL missing ANSEL pin config"
#endif
#ifndef MODULES_CONFIG_PIR_PORT
#error "modules_config.h MODULES_CONFIG_PIR_PORT missing PORT pin config"
#endif
