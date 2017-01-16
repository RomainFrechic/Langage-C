/* ---------------------------------------------------------------------
   (c) ED 2000-2004
   Projet       : CLIB
   Fonction     : Min/Max values memory
   Module       : STAT
   Fichier      : STAT.C
   Creation     : 26-01-2000
   Modification : 15-12-2004
   --------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
   Journal

   0.0 du 26-01-2000 Creation
   1.0 du 26-01-2000 Version operationelle
   1.1 du 15-12-2004 Les fonction de creation/destruction deviennent
   .                 create/delete. des macros init/end assurent
   .                 la compatibilite ascendante.
   .                 Mise au format ADT

   --------------------------------------------------------------------- */
#ifdef __cplusplus
#error This source file is not C++ but C. Please use a C compiler.
#endif


#include "ed/inc/sys.h"
#include "ed/inc/sysalloc.h"

/* macros ============================================================== */
#define MODULE "STAT"
#define VER "1.1"
#define ID "STAT Module \"C\" (c) ED 2000-2004"

/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */

struct STAT
{
   sSTAT_RESULTS result;
};

/* private data ======================================================== */
/* private functions =================================================== */

/* ---------------------------------------------------------------------
   test()
   ---------------------------------------------------------------------
   Role :
   ---------------------------------------------------------------------
   E :
   S :
   --------------------------------------------------------------------- */
static void test (sSTAT * this, ulong val)
{
   assert (this != NULL);
   /*  code de la fonction */

   {
      sSTAT_RESULTS *pResult = &this->result;

      if (pResult->min > val)
      {
         pResult->min = val;
      }

      if (pResult->max < val)
      {
         pResult->max = val;
      }

      if (pResult->count < ULONG_MAX)
      {
         pResult->count++;
      }
      else
      {
         pResult->overflow = 1;
      }
   }
}

/* internal public data ================================================ */
/* internal public functions =========================================== */
/* entry points ======================================================== */

/* ---------------------------------------------------------------------
   STAT_sver()
   ---------------------------------------------------------------------
   Role : Retourne une chaine "Version"
   ---------------------------------------------------------------------
   E :
   S : Pointeur de chaine ASCIIZ
   --------------------------------------------------------------------- */
const char *STAT_sver (void)
{
   return VER;
}

/* ---------------------------------------------------------------------
   STAT_sid()
   ---------------------------------------------------------------------
   Role : Retourne une chaine "Identification"
   ---------------------------------------------------------------------
   E :
   S : Pointeur de chaine ASCIIZ
   --------------------------------------------------------------------- */
const char *STAT_sid (void)
{
   return ID;
}

/* ---------------------------------------------------------------------
   STAT_create()
   ---------------------------------------------------------------------
   Role : Creation/Initialisation
   ---------------------------------------------------------------------
   E :
   S : Pointeur de donnees
   --------------------------------------------------------------------- */
sSTAT *STAT_create (void)
{
   sSTAT *this = NULL;

   ENUM_CHECK ();

   this = malloc (sizeof *this);

   if (this != NULL)
   {
      SYS_CLR (this, sSTAT);

      {
         sSTAT_RESULTS *pResult = &this->result;

         pResult->min = ULONG_MAX;
         pResult->max = 0;
      }

   }
   return this;
}

/* ---------------------------------------------------------------------
   STAT_delete()
   ---------------------------------------------------------------------
   Role : Suppression
   ---------------------------------------------------------------------
   E : Pointeur de donnees
   S :
   --------------------------------------------------------------------- */
void STAT_delete (sSTAT * this)
{
   if (this != NULL)
   {
      free (this);
   }
}

/* ---------------------------------------------------------------------
   STAT_test()
   ---------------------------------------------------------------------
   Role : test une valeur et garde les valeurs min et max
   ---------------------------------------------------------------------
   E : Pointeur de donnees
   E : Valeur a tester
   S :
   --------------------------------------------------------------------- */
void STAT_test (sSTAT * this, ulong val)
{
   if (this != NULL)
   {
      test (this, val);
   }
}

/* ---------------------------------------------------------------------
   STAT_read()
   ---------------------------------------------------------------------
   Role : lire les resultats
   ---------------------------------------------------------------------
   E : Pointeur de donnees
   E : Pointeur de resultats
   S :
   --------------------------------------------------------------------- */
void STAT_read (sSTAT * this, sSTAT_RESULTS * pResult)
{
   if (this != NULL)
   {
      if (pResult != NULL)
      {
         /*  code de la fonction */
         *pResult = this->result;
      }
   }
}

/* public data ========================================================= */

/* File generated by 'NEW.EXE' Ver 1.20 (c) ED 1998-99 */
