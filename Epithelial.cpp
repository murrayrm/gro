/////////////////////////////////////////////////////////////////////////////////////////
//
// gro is protected by the UW OPEN SOURCE LICENSE, which is summarized here.
// Please see the file LICENSE.txt for the complete license.
//
// THE SOFTWARE (AS DEFINED BELOW) AND HARDWARE DESIGNS (AS DEFINED BELOW) IS PROVIDED
// UNDER THE TERMS OF THIS OPEN SOURCE LICENSE (“LICENSE”).  THE SOFTWARE IS PROTECTED
// BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.  ANY USE OF THIS SOFTWARE OTHER THAN AS
// AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.
//
// BY EXERCISING ANY RIGHTS TO THE SOFTWARE AND/OR HARDWARE PROVIDED HERE, YOU ACCEPT AND
// AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.  TO THE EXTENT THIS LICENSE MAY BE
// CONSIDERED A CONTRACT, THE UNIVERSITY OF WASHINGTON (“UW”) GRANTS YOU THE RIGHTS
// CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
//
// TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
//
// Epithelial was developed by Liana Merk, Murray Lab Caltech
// Adapted from Yeast class
// This cell type does not grow and divide.

#include "Epithelial.h"
#include "Programs.h"

Epithelial::Epithelial ( World * w, float x, float y, float a, float v)
: Cell ( w ), volume ( v ) {

  float r = radius();

  // Epithelial cells are static and will not be pushed by other dividing cells
  cpBody *body = cpBodyNewStatic();

  body->p = cpv ( x, y );
  body->v = cpv ( 0, 0 );
  body->a = a;
  body->m = 1;

  // Epithelial cells are round, and user can set radius in gro file
  shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius(), cpvzero));

  int i;
  for ( i=0; i<MAX_STATE_NUM; i++ ) q[i] = 0;
  for ( i=0; i<MAX_REP_NUM; i++ ) rep[i] = 0;

}

#define YFMULT 500

// Cells can fluoresce just like other Microbe celltypes.
void Epithelial::render ( Theme * theme, GroPainter * painter  ) {

  float r = radius();
  float vol;

  vol = volume;

  double
    gfp = 500*( rep[GFP] / vol - world->get_param ( "gfp_saturation_min" ) ) / ( world->get_param ( "gfp_saturation_max" ) - world->get_param ( "gfp_saturation_min" ) ),
    rfp = 500*( rep[RFP] / vol - world->get_param ( "rfp_saturation_min" ) ) / ( world->get_param ( "rfp_saturation_max" ) - world->get_param ( "rfp_saturation_min" ) ),
    yfp = 500*( rep[YFP] / vol - world->get_param ( "yfp_saturation_min" ) ) / ( world->get_param ( "yfp_saturation_max" ) - world->get_param ( "yfp_saturation_min" ) ),
    cfp = 500*( rep[CFP] / vol - world->get_param ( "cfp_saturation_min" ) ) / ( world->get_param ( "cfp_saturation_max" ) - world->get_param ( "cfp_saturation_min" ) );

  theme->apply_ecoli_edge_color ( painter, is_selected() );

  QColor col;

  col.setRgbF( qMax(0.0,qMin(1.0,rfp + yfp)),
               qMax(0.0,qMin(1.0,gfp + yfp + cfp)),
               qMax(0.0,qMin(1.0,cfp)),
               0.75);

  painter->setBrush(col);
  QPointF center (get_x(),get_y());

  painter->drawEllipse(center,r,r);

  return;

}

void Epithelial::update ( void ) {

  if ( program != NULL )
      program->update ( world, this );

  cpCircleShapeSetRadius ( shape, radius() );

}
