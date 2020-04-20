#include "lsf_confer.h"

Confer *
lsf_get_confer (char *config_path,
                int   reload_flag)
{
  GError *error = NULL;

  if (reload_flag)
  {
    g_key_file_free (confer->key_file);
  }
  else if (confer != NULL)
  {
    return confer;
  }

  confer = (Confer *) malloc (sizeof (Confer));

  confer->key_file = g_key_file_new ();

  if (!g_key_file_load_from_file (confer->key_file, config_path, G_KEY_FILE_NONE, &error))
  {
    if (!g_error_matches (error, G_FILE_ERROR, G_FILE_ERROR_NOENT)
        || !g_error_matches (error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_NOT_FOUND))
    {
      g_error ("Error loading key file: %s\n", error->message);
    }
    g_error_free (error);

    return NULL; 
  }
  return confer;
}

void
lsf_confer_free (void)
{
  g_key_file_free (confer->key_file);
  free (confer);
}

gchar *
lsf_confer_get_str (char *section,
                    char *key)
{
  GError *error = NULL;
  gchar *value;

  if (confer->key_file == NULL) 
  {
    g_error ("Cannot read the key file.");
    return NULL;
  }

  value = g_key_file_get_string (confer->key_file, section, key, &error);

  if (value == NULL)
  {
    if (!g_error_matches (error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_GROUP_NOT_FOUND))
    {
      g_error ("Error finding section in key file: %s\n", error->message);
      g_error_free (error);
    }
    else if (!g_error_matches (error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_KEY_NOT_FOUND))
    {
      g_error ("Error finding key in key file: %s\n", error->message);
      g_error_free (error);
    }
    else
    {
      g_warning ("No Value for the Section:[%s]\nKey:%s.\n", section, key);
    }
    return NULL;
  }

  return value;
}
