#ifndef FICHIER_H
  #define FICHIER_H

  #include <stdlib.h>
  #include <stdio.h>
  #include <errno.h>
  #include "Debut.h"
  #include "Utile.h"

  Game save(Game g);
  Game openSave(Game g);
  void HighScore(Game g);

  
#endif
