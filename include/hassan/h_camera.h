/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/
#ifndef _HASSAN_H_CAMERA_H
#define _HASSAN_H_CAMERA_H
//#include<values.h>
#include"private/video_win.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Camera_V
{
   public :
      
      Camera_V( ) : 
                    _zoom(40),
                    _teta(0),
                    _phi(PI/4),
                    _rho(50),             //centre du camera
                    _d_zoom(.1),
                    _d_teta(PI/50),
                    _d_phi(PI/50),
                    _d_rho(.1),
                    _x_c(0),              //centre du monde
                    _y_c(0),
                    _z_c(0),
                    _avant_arrier(false),
                    _W(0),
                    _nb_color(63)  {  _m30 = 0;  _m31 = 0;  _m32 = 0;  _m33 = 1;
                                      _tx_1_2 = 400;
                                      _ty_1_2 = 350;
                                   }

      Camera_V(Camera_V& camera)
                                   {  _m00 = camera._m00;  _m01 = camera._m01;  _m02 = camera._m02 ;  _m03 = camera._m03;
                                      _m10 = camera._m10;  _m11 = camera._m11;  _m12 = camera._m12 ;  _m13 = camera._m13;
                                      _m20 = camera._m20;  _m21 = camera._m21;  _m22 = camera._m22 ;  _m23 = camera._m23;
                                      _m30 = camera._m30;  _m31 = camera._m31;  _m32 = camera._m32 ;  _m33 = camera._m33;
                                      _zoom = camera._zoom; _teta = camera._teta; _phi = camera._phi;  _rho = camera._rho;
                                      _d_zoom = camera._d_zoom; _d_teta = camera._d_teta; 
                                      _d_phi = camera._d_phi;  _d_rho = camera._d_rho;
                                      _x_c = camera._x_c;   _y_c = camera._y_c;   _z_c = camera._z_c;
                                      _tx_1_2 = camera._tx_1_2;
                                      _ty_1_2 = camera._ty_1_2;
                                      _avant_arrier = camera._avant_arrier;
                                      _nb_color = camera._nb_color;
                                   }


      virtual ~Camera_V(){
                            if(_W)
                            {
                               XCloseDisplay(_W->display().mDisp);
                               delete _W;
                              _W = 0;
                            }
                         } 


//   protected :
      
      REAL _m00, _m01, _m02, _m03;
      REAL _m10, _m11, _m12, _m13;
      REAL _m20, _m21, _m22, _m23;
      REAL _m30, _m31, _m32, _m33;
      REAL _zoom;
      REAL _teta;
      REAL _phi;
      REAL _rho;
      REAL _d_zoom;
      REAL _d_teta;
      REAL _d_phi;
      REAL _d_rho;
      REAL _x_c;
      REAL _y_c;
      REAL _z_c;
      INT  _tx_1_2;
      INT  _ty_1_2;
      bool _avant_arrier;

      Video_Win* _W;
      INT       _nb_color;


                                      // mouvement de camera



      inline void vitesse(INT i = 1)                { (i>0)? plus_vite(i) : moins_vite(i); } 
      inline void plus_vite(INT i = 1)              { while(i--){_d_zoom *= 1.00001; _d_teta *= 1.00001; _d_phi *= 1.00001;_d_rho *= 1.00001;}   } 
      inline void moins_vite(INT i = 1)             { while(i--){_d_zoom *= .99999;  _d_teta *= .99999;  _d_phi *= .99999; _d_rho *= .99999;}    } 
      inline void zoom(REAL i = 1)                  {   _zoom *= (1 + i*_d_zoom);_zoom = (_zoom>300)? 300 : (_zoom<.2)? .2:_zoom; }
      inline void zoom_up()                         {   _zoom *= (1 + _d_zoom);  _zoom = (_zoom>195)? 195:_zoom; }
      inline void zoom_down()                       {   _zoom *= (1 - _d_zoom);  _zoom = (_zoom<.2)? .2:_zoom; }
      inline void approche_up()                     {   _rho *= (1 + _d_rho);    _rho  = (_rho>900)? 900:_rho; }
      inline void approche_down()                   {   _rho *= (1 - _d_rho);    _rho  = (_rho<1)? 1:_rho; }
      inline void tourne_objet (REAL i=1, REAL j=0) {   _teta += (i *_d_teta); _phi += (j * _d_phi); }
      inline void tourne_camera(REAL i=1, REAL j=0) {
                                                       REAL teta = _teta + i * _d_teta * .1;
                                                       REAL phi  = _phi  + j * _d_phi  * .1;
                                                       _x_c -= _rho * ( 2 * sin(_phi) * cos(_teta) - sin(phi) * cos(_teta) - sin(_phi) * cos(teta));
                                                       _y_c -= _rho * ( 2 * sin(_phi) * sin(_teta) - sin(phi) * sin(_teta) - sin(_phi) * sin(teta));
                                                      _z_c -= _rho * (cos(_phi) - cos(phi));
                                                      _teta = teta;
                                                      _phi  = phi;
                                                    }

                                        //parametre de camera

      inline void calcul_matrice() {   _m00 = -sin(_teta) * _zoom;
                                       _m01 =  cos(_teta) * _zoom;
                                       _m02 =  0;
                                       _m03 = -_x_c * _m00 - _y_c * _m01 + _tx_1_2;
                                       _m10 =  cos(_phi) * cos(_teta) * _zoom;
                                       _m11 =  cos(_phi) * sin(_teta) * _zoom;
                                       _m12 = -sin(_phi) * _zoom;
                                       _m13 = -_x_c * _m10 - _y_c * _m11 - _z_c * _m12 + _ty_1_2;
                                       _m20 = -sin(_phi) * cos(_teta) * _zoom;
                                       _m21 = -sin(_phi) * sin(_teta) * _zoom;
                                       _m22 = -cos(_phi) * _zoom;
                                       _m23 = -_x_c * _m20 - _y_c * _m21 - _z_c * _m22 + _rho;
                                   }


      virtual void reperer(){}
      virtual void zoom_adjuster(){}

      Pt2di   projeter(Pt3dr p){
                                  return Pt2di(
                                                 (INT)(_m00 * p.x + _m01 * p.y + _m02 * p.z + _m03),
                                                 (INT)(_m10 * p.x + _m11 * p.y + _m12 * p.z + _m13)
                                               );
                               }

                                        // afficahge et desaffichage

   protected :

      virtual void afficher()        { }
      virtual void desafficher()     {  _W->clear();}
      void reafficher()              {   calcul_matrice();   afficher();    }

   public  :


      Video_Win* window()            {   return _W; }
      INT       nb_color()           {   return _nb_color; }

      virtual void interface()       {
                                         Gray_Pal       Pgray  (100);
                                         Disc_Pal       Pdisc  = palette_64();
                                         Elise_Set_Of_Palette Sop(NewLElPal(Pgray)+Elise_Palette(Pdisc));
                                         Video_Display Ecr((char *) NULL);
                                         Ecr.load(Sop);
                                         Pt2di taille_fenetre(_tx_1_2, _ty_1_2);

                                         if(!_W) _W = new Video_Win(Ecr,Sop,Pt2di(30,30),taille_fenetre * 2);
                                         _nb_color = 64;
                                         reafficher();


                                         INT x  = 0;
                                         INT y  = 0;
                                         INT x1 = 0;
                                         INT y1 = 0;
                                         INT x2 = 0;
                                         INT y2 = 0;
                                         INT dzoom = 0;
                                         REAL tempsecoule=0;
                                         REAL time1 = 0;
                                         REAL time2 = 0;
                                         bool objet = true;
                                         bool affichage = false;
                                         Display * display = _W->display().mDisp;
                                         Window window = _W->window().mW;
                                         XEvent event;
                                         XEvent event_last;
                                         char buffer[20];
                                         INT  bufsize = 20;
                                         KeySym keysym = XK_a;
                                         XComposeStatus compose;
                                         INT charcount;
                                         XSelectInput(   display,
                                                         window,
                                                         KeyPressMask
                                                       | KeyReleaseMask
                                                       | ButtonPressMask
                                                       | ButtonReleaseMask
                                                                   | Button1MotionMask
                                                     );
                                         while(keysym != XK_q)
                                         {
                                            if(
                                                 XCheckWindowEvent(   display,
                                                                      window,
                                                                      KeyPressMask
                                                                    | KeyReleaseMask
                                                                    | ButtonPressMask
                                                                    | ButtonReleaseMask
                                                                    | Button1MotionMask
                                                                    ,
                                                                    &event
                                                                  )
                                              )
                                            {
                                               if(event.type == KeyPress)
                                               {
                                                  time2 = event.xkey.time;
                                                  charcount = XLookupString(&(event.xkey), buffer, bufsize, &keysym, &compose);
                                                  switch(keysym)
                                                  {
                                                     case  XK_Left :  x++;             affichage = true; break;
                                                     case  XK_Right:  x--;             affichage = true; break;
                                                     case  XK_Up   :  y++;             affichage = true; break;
                                                     case  XK_Down :  y--;             affichage = true; break;
                                                     case  XK_z    :  dzoom++;         affichage = true; break;
                                                     case  XK_a    :  dzoom--;         affichage = true; break;
                                                     case  XK_e    :  approche_up();   affichage = false; break;
                                                     case  XK_r    :  approche_down(); affichage = false; break;
                                                     case  XK_t    :  objet = false;   affichage = false; break;
                                                     case  XK_y    :  objet = true;    affichage = false; break;
                                                     case  XK_q    :  desafficher();   affichage = false; break;
                                                     case  XK_v    :  plus_vite();     affichage = false; break;
                                                     case  XK_c    :  moins_vite();    affichage = false; break;
                                                  }
                                               }
                                               else if(event.type ==  ButtonPress)
                                               {
                                                  XButtonEvent b_e = event.xbutton;
                                                  x1 = b_e.x;
                                                  y1 = b_e.y;
                                                  time1 = b_e.time;
                                                  tempsecoule = 0;
                                                  affichage = true;
                                               }
                                               else if(event.type == MotionNotify)
                                               {
                                                  XMotionEvent m_e = event.xmotion;

                                                  x2 = m_e.x;
                                                  y2 = m_e.y;
                                                  time2 = m_e.time;
                                                  affichage = true;
                                               }
                                               if( affichage && tempsecoule < (time2 - time1) )
                                               {
                                                  clock_t debut = clock();
                                                   
                                                  REAL dx = .05 * (x1 - x2) + x;
                                                  REAL dy = .05 * (y1 - y2) + y;
                                      
                                                  if(objet) tourne_objet (dx, dy);
                                                  else      tourne_camera(dx, dy);
                                                  zoom(dzoom);
                                                  reafficher();

                                                  dzoom = 0;
                                                  x1 = x2;
                                                  y1 = y2;
                                                  x = 0;
                                                  y = 0;
                                                  time1 = time2;

                                                  clock_t fin = clock();
                                                  tempsecoule = (REAL)(fin - debut)/CLOCKS_PER_SEC * 1000;
                                               }

                                               event = event_last;
                                            }
                                         }
                                     } 
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Camera_F:public Camera_V
{
   public:

      Camera_F( ElFilo<Facette_3d>& lface );
      Camera_F( Camera_V& camera, ElFilo<Facette_3d>& lface);
      
      virtual ~Camera_F(){} 

   protected:

      ElList<ElList<Pt2di> > _ll;
      ElList<Facette_3d> _lface;

      virtual void reperer();
      virtual void zoom_adjuster();
      virtual void afficher();

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Camera_P_F:public Camera_V
{
   public:

      Camera_P_F( 
                  ElFilo<Pt3dr>&      f_pt,
                  ElFilo<Facette_3d>& f_face
                );
      Camera_P_F( Camera_V&           camera,
                  ElFilo<Pt3dr>&      f_p,
                  ElFilo<Facette_3d>& f_face
                );

      virtual ~Camera_P_F(){}

   protected:

      ElFilo<Pt3dr>&          _f_pt;
      ElFilo<Facette_3d>&     _f_face;

      virtual void reperer();
      virtual void zoom_adjuster();
      virtual void afficher();

};


////////////////////////////////////////////////////////////////////////////////


class Camera_MNE_F:public Camera_V
{
   public:

      Camera_MNE_F( 
                    Mne&                mne,
                    ElFilo<Facette_3d>& f_face
                  );
      Camera_MNE_F( Camera_V&           camera,
                    Mne&                mne,
                    ElFilo<Facette_3d>& f_face
                  );

      virtual ~Camera_MNE_F(){}

   protected:

      INT2**              _mne;

      INT2                _label_interdit;
      INT                 _tx_mne;
      INT                 _ty_mne;

      Im1D_REAL4          _im_x00;
      Im1D_REAL4          _im_x10;
      Im1D_REAL4          _im_y01;
      Im1D_REAL4          _im_y11;
      REAL4*              _im_x00_d;
      REAL4*              _im_x10_d;
      REAL4*              _im_y01_d; 
      REAL4*              _im_y11_d; 

      INT                 _tx_W;
      INT                 _ty_W;

      ElFilo<Facette_3d>  _f_face;

      virtual void reperer();
      virtual void zoom_adjuster();
      virtual void afficher();

};

////////////////////////////////////////////////////////////////////////////////


class Camera_G:public Camera_V
{
   public:

      Camera_G( H_Graphe& graphe );
      Camera_G(Camera_V& camera, H_Graphe& graphe);

      virtual ~Camera_G();

   protected:

      H_Graphe&     _graphe;

      INT    _nb_som;
      Pt3dr* _som;
      INT*   _som_flag;

      INT    _nb_seg;
      INT*   _seg0;
      INT*   _seg1;
      INT*   _seg_flag;

      Pt2di*        _p_proj;

      virtual void reperer();
      virtual void afficher();
      virtual void zoom_adjuster();
      virtual void desafficher();
      virtual void interface();

      void parcour_seg_facet();
      void parcour_segment();
      void parcour_facette();

};


void affiche_plans(vector<double>& par_plans, vector<double>& polygone, double z_min, double z_max);



#endif 

/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
