#ifndef PS_H_
#define PS_H_
struct ps{
      double alff,all,hhh,qqq,ooo,v,t,tau,h0,h10,t10,dh,qf,ie,p_e,h430,ro430,t24,h24;
      double pi,palf,palf1,pl,ph;
      double salf1,salf2,salf3,salf4,salf,ph1,sh1,sh2,sh3,sh;
      double pl1,sl1,sl2,sl3,sl;
      double pq,dq,pv,pv1,vv,dpv,grt10,pt10,grt,pt,pho,dti,ps,po,ph0;
      double aqq,dt10;
      double p,p1,p2,p3;
      double alfa[1000],ll[1000],hh[1000],qq[1000],oo[1000],vvv[1000];
      double smax[6],smin[6];
      double c1[6],c2[6],an1,an2,r1,r2,l1,l2;
      double ks,kp,ke,qs,u1,u2,w1,w2,alf,al,h,q,o;
      int n,m,cs[1000],i1,icod;
};

void obraz(struct ps *pss);

void frcst(struct ps *pss);
void ps1(struct ps *pss);

void ps2(struct ps *pss);

void ps3(struct ps *pss);
#endif /* PS_H_ */