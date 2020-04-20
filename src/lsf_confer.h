#ifndef __LSF_CONFER_H__
#define __LSF_CONFER_H__

#include <glib.h>
#include <glib/gprintf.h>

#define LSF_CONFER_CONFIG "/home/haru/haru_project/lsf/lsf_confer/conf/log.conf"

enum {
  CONFER_GROUP,
  CONFER_KEY,
  CONFER_VALUE,
  CONFER_OPT_FLAG_NUMS
};

typedef struct {
  GKeyFile *key_file;
} Confer;

Confer *confer;

extern Confer  *lsf_get_confer            (char *config_file, int reload_flag);
extern gchar   *lsf_confer_get_str        (char *section, char *key);
extern void     lsf_confer_set_str        (char *section, char *key, char *value);
extern gboolean lsf_confer_save           (char *output_path);
extern gboolean lsf_confer_remove_section (char *group_name);
extern gboolean lsf_confer_remove_key     (char *group_name, char *key_name);
extern void     lsf_confer_free           (void);

#endif
