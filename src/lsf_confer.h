#ifndef __LSF_CONFER_H__
#define __LSF_CONFER_H__

#include <glib.h>
#include <glib/gprintf.h>

typedef struct {
  GKeyFile *key_file;
} Confer;

Confer *confer;

extern Confer *lsf_get_confer     (char *config_file, int reload_flag);
extern gchar  *lsf_confer_get_str (char *section, char *key);
extern void    lsf_confer_free    (void);

#endif
