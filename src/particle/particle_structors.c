/* 
 * Written by:
 *   Kevin J. Bowers, Ph.D.
 *   Plasma Physics Group (X-1)
 *   Applied Physics Division
 *   Los Alamos National Lab
 * March/April 2004 - Original version
 *
 */

#include <particle.h>

particle_t * ALIGNED(128)
new_particle_array( int np ) {
  particle_t * ALIGNED(128) p;

  if( np<1 ) ERROR(("Bad np"));

  p = (particle_t * ALIGNED(128))malloc_aligned( np*sizeof(particle_t), 128 );
  if( p==NULL ) ERROR(("Failed to allocate particle array."));
  memset( p, 0, np*sizeof(p[0]) );

  return p;
}

void
delete_particle_array( particle_t ** ALIGNED(128) p ) {
  if( p==NULL ) return;
  if( *p!=NULL ) free_aligned(*p);
  *p = NULL;
}

particle_mover_t * ALIGNED(128)
new_particle_mover( int nm ) {
  particle_mover_t * ALIGNED(128) pm;

  if( nm<1 ) ERROR(("Bad nm"));

  pm = (particle_mover_t * ALIGNED(128))
    malloc_aligned( nm*sizeof(particle_mover_t), 128 );
  if( pm==NULL ) ERROR(("Failed to allocate particle mover."));
  memset( pm, 0, nm*sizeof(pm[0]) );

  return pm;
}

void
delete_particle_mover( particle_mover_t ** ALIGNED(128) pm ) {
  if( pm==NULL ) return;
  if( *pm!=NULL ) free_aligned(*pm);
  *pm = NULL;
}
