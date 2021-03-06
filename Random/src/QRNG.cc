/* Author: G. Jungman
 */
#include <stdlib.h>
#include <string.h>

#include "CLHEP/Random/QRNG.h"



qrng::qrng (unsigned int dimension)
{

  this->dimension = dimension;
  
  //r->state_size = T->state_size(dimension);
  //state = new qrng_state();//malloc (r->state_size);

/*  if (r->state == 0)
    {
      free (r);
      GSL_ERROR_VAL ("allocation failed for qrng state",
                        GSL_ENOMEM, 0);
    };

  r->type = T;

  T->init_state(r->state, r->dimension);

  return r;*/
}

void qrng::init ()
{
 /* (r->type->init_state) (r->state, r->dimension);*/
 state->init();
}

qrng::qrng (const qrng * src)
{

  dimension = src->dimension;
  state = src->state;
  /*dest->state_size = src->state_size;
  memcpy (dest->state, src->state, src->state_size);

  return GSL_SUCCESS;*/
}

/*
gsl_qrng *
gsl_qrng_clone (const gsl_qrng * q)
{
  gsl_qrng * r = (gsl_qrng *) malloc (sizeof (gsl_qrng));

  if (r == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for rng struct",
                        GSL_ENOMEM, 0);
    };

  r->dimension = q->dimension;
  r->state_size = q->state_size;
  r->state = malloc (r->state_size);

  if (r->state == 0)
    {
      free (r);
      GSL_ERROR_VAL ("failed to allocate space for rng state",
                        GSL_ENOMEM, 0);
    };

  r->type = q->type;

  memcpy (r->state, q->state, q->state_size);

  return r;
}
*/

void qrng::get (double x[])
{
  state->get (x);
}
/*

const char *
gsl_qrng_name (const gsl_qrng * r)
{
  return r->type->name;
}


size_t
gsl_qrng_size (const gsl_qrng * r)
{
  return r->state_size;
}


void *
gsl_qrng_state (const gsl_qrng * r)
{
  return r->state;
}
*/


