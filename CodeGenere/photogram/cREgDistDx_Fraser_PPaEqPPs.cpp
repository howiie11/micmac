// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cREgDistDx_Fraser_PPaEqPPs.h"


cREgDistDx_Fraser_PPaEqPPs::cREgDistDx_Fraser_PPaEqPPs():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,12));
   Close(false);
}



void cREgDistDx_Fraser_PPaEqPPs::ComputeVal()
{
   double tmp0_ = mCompCoord[1];
   double tmp1_ = mLocRegDistu1_x - tmp0_;
   double tmp2_ = mCompCoord[2];
   double tmp3_ = mLocRegDistu1_y - tmp2_;
   double tmp4_ = (tmp1_) * (tmp1_);
   double tmp5_ = (tmp3_) * (tmp3_);
   double tmp6_ = tmp4_ + tmp5_;
   double tmp7_ = (tmp6_) * (tmp6_);
   double tmp8_ = tmp7_ * (tmp6_);
   double tmp9_ = tmp8_ * (tmp6_);
   double tmp10_ = mCompCoord[3];
   double tmp11_ = mLocRegDistu2_x - tmp0_;
   double tmp12_ = mLocRegDistu2_y - tmp2_;
   double tmp13_ = mCompCoord[4];
   double tmp14_ = (tmp11_) * (tmp11_);
   double tmp15_ = (tmp12_) * (tmp12_);
   double tmp16_ = tmp14_ + tmp15_;
   double tmp17_ = mCompCoord[5];
   double tmp18_ = (tmp16_) * (tmp16_);
   double tmp19_ = mCompCoord[6];
   double tmp20_ = tmp18_ * (tmp16_);
   double tmp21_ = mCompCoord[7];
   double tmp22_ = tmp20_ * (tmp16_);
   double tmp23_ = mCompCoord[8];
   double tmp24_ = mCompCoord[9];
   double tmp25_ = mCompCoord[10];
   double tmp26_ = mCompCoord[11];
   double tmp27_ = tmp10_ * (tmp6_);
   double tmp28_ = tmp13_ * tmp7_;
   double tmp29_ = tmp27_ + tmp28_;
   double tmp30_ = tmp17_ * tmp8_;
   double tmp31_ = tmp29_ + tmp30_;
   double tmp32_ = tmp19_ * tmp9_;
   double tmp33_ = tmp31_ + tmp32_;
   double tmp34_ = tmp9_ * (tmp6_);
   double tmp35_ = tmp21_ * tmp34_;
   double tmp36_ = tmp33_ + tmp35_;
   double tmp37_ = (tmp1_) * (tmp3_);
   double tmp38_ = 2 * tmp37_;
   double tmp39_ = tmp10_ * (tmp16_);
   double tmp40_ = tmp13_ * tmp18_;
   double tmp41_ = tmp39_ + tmp40_;
   double tmp42_ = tmp17_ * tmp20_;
   double tmp43_ = tmp41_ + tmp42_;
   double tmp44_ = tmp19_ * tmp22_;
   double tmp45_ = tmp43_ + tmp44_;
   double tmp46_ = tmp22_ * (tmp16_);
   double tmp47_ = tmp21_ * tmp46_;
   double tmp48_ = tmp45_ + tmp47_;
   double tmp49_ = (tmp11_) * (tmp12_);
   double tmp50_ = 2 * tmp49_;

  mVal[0] = (mLocRegDistu1_x + (tmp1_) * (tmp36_) + (2 * tmp4_ + tmp6_) * tmp23_ + tmp38_ * tmp24_ + tmp25_ * (tmp1_) + tmp26_ * (tmp3_)) - (mLocRegDistu2_x + (tmp11_) * (tmp48_) + (2 * tmp14_ + tmp16_) * tmp23_ + tmp50_ * tmp24_ + tmp25_ * (tmp11_) + tmp26_ * (tmp12_)) - mLocRegDistu3_x;

  mVal[1] = (mLocRegDistu1_y + (tmp3_) * (tmp36_) + (2 * tmp5_ + tmp6_) * tmp24_ + tmp38_ * tmp23_) - (mLocRegDistu2_y + (tmp12_) * (tmp48_) + (2 * tmp15_ + tmp16_) * tmp24_ + tmp50_ * tmp23_) - mLocRegDistu3_y;

}


void cREgDistDx_Fraser_PPaEqPPs::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[1];
   double tmp1_ = mLocRegDistu1_x - tmp0_;
   double tmp2_ = mCompCoord[2];
   double tmp3_ = mLocRegDistu1_y - tmp2_;
   double tmp4_ = (tmp1_) * (tmp1_);
   double tmp5_ = (tmp3_) * (tmp3_);
   double tmp6_ = tmp4_ + tmp5_;
   double tmp7_ = (tmp6_) * (tmp6_);
   double tmp8_ = tmp7_ * (tmp6_);
   double tmp9_ = tmp8_ * (tmp6_);
   double tmp10_ = mCompCoord[3];
   double tmp11_ = mLocRegDistu2_x - tmp0_;
   double tmp12_ = mLocRegDistu2_y - tmp2_;
   double tmp13_ = mCompCoord[4];
   double tmp14_ = (tmp11_) * (tmp11_);
   double tmp15_ = (tmp12_) * (tmp12_);
   double tmp16_ = tmp14_ + tmp15_;
   double tmp17_ = mCompCoord[5];
   double tmp18_ = (tmp16_) * (tmp16_);
   double tmp19_ = mCompCoord[6];
   double tmp20_ = tmp18_ * (tmp16_);
   double tmp21_ = mCompCoord[7];
   double tmp22_ = tmp20_ * (tmp16_);
   double tmp23_ = mCompCoord[8];
   double tmp24_ = mCompCoord[9];
   double tmp25_ = mCompCoord[10];
   double tmp26_ = mCompCoord[11];
   double tmp27_ = tmp10_ * (tmp6_);
   double tmp28_ = tmp13_ * tmp7_;
   double tmp29_ = tmp27_ + tmp28_;
   double tmp30_ = tmp17_ * tmp8_;
   double tmp31_ = tmp29_ + tmp30_;
   double tmp32_ = tmp19_ * tmp9_;
   double tmp33_ = tmp31_ + tmp32_;
   double tmp34_ = tmp9_ * (tmp6_);
   double tmp35_ = tmp21_ * tmp34_;
   double tmp36_ = tmp33_ + tmp35_;
   double tmp37_ = -(1);
   double tmp38_ = tmp37_ * (tmp1_);
   double tmp39_ = tmp38_ + tmp38_;
   double tmp40_ = (tmp39_) * (tmp6_);
   double tmp41_ = tmp40_ + tmp40_;
   double tmp42_ = (tmp41_) * (tmp6_);
   double tmp43_ = (tmp39_) * tmp7_;
   double tmp44_ = tmp42_ + tmp43_;
   double tmp45_ = (tmp44_) * (tmp6_);
   double tmp46_ = (tmp39_) * tmp8_;
   double tmp47_ = tmp45_ + tmp46_;
   double tmp48_ = tmp10_ * (tmp16_);
   double tmp49_ = tmp13_ * tmp18_;
   double tmp50_ = tmp48_ + tmp49_;
   double tmp51_ = tmp17_ * tmp20_;
   double tmp52_ = tmp50_ + tmp51_;
   double tmp53_ = tmp19_ * tmp22_;
   double tmp54_ = tmp52_ + tmp53_;
   double tmp55_ = tmp22_ * (tmp16_);
   double tmp56_ = tmp21_ * tmp55_;
   double tmp57_ = tmp54_ + tmp56_;
   double tmp58_ = tmp37_ * (tmp11_);
   double tmp59_ = tmp58_ + tmp58_;
   double tmp60_ = (tmp59_) * (tmp16_);
   double tmp61_ = tmp60_ + tmp60_;
   double tmp62_ = (tmp61_) * (tmp16_);
   double tmp63_ = (tmp59_) * tmp18_;
   double tmp64_ = tmp62_ + tmp63_;
   double tmp65_ = (tmp64_) * (tmp16_);
   double tmp66_ = (tmp59_) * tmp20_;
   double tmp67_ = tmp65_ + tmp66_;
   double tmp68_ = tmp37_ * tmp25_;
   double tmp69_ = tmp37_ * (tmp3_);
   double tmp70_ = tmp69_ + tmp69_;
   double tmp71_ = (tmp70_) * (tmp6_);
   double tmp72_ = tmp71_ + tmp71_;
   double tmp73_ = (tmp72_) * (tmp6_);
   double tmp74_ = (tmp70_) * tmp7_;
   double tmp75_ = tmp73_ + tmp74_;
   double tmp76_ = (tmp75_) * (tmp6_);
   double tmp77_ = (tmp70_) * tmp8_;
   double tmp78_ = tmp76_ + tmp77_;
   double tmp79_ = tmp37_ * (tmp12_);
   double tmp80_ = tmp79_ + tmp79_;
   double tmp81_ = (tmp80_) * (tmp16_);
   double tmp82_ = tmp81_ + tmp81_;
   double tmp83_ = (tmp82_) * (tmp16_);
   double tmp84_ = (tmp80_) * tmp18_;
   double tmp85_ = tmp83_ + tmp84_;
   double tmp86_ = (tmp85_) * (tmp16_);
   double tmp87_ = (tmp80_) * tmp20_;
   double tmp88_ = tmp86_ + tmp87_;
   double tmp89_ = tmp37_ * tmp26_;
   double tmp90_ = 2 * tmp4_;
   double tmp91_ = tmp90_ + tmp6_;
   double tmp92_ = 2 * tmp14_;
   double tmp93_ = tmp92_ + tmp16_;
   double tmp94_ = (tmp1_) * (tmp3_);
   double tmp95_ = 2 * tmp94_;
   double tmp96_ = (tmp11_) * (tmp12_);
   double tmp97_ = 2 * tmp96_;
   double tmp98_ = (tmp39_) * tmp10_;
   double tmp99_ = (tmp41_) * tmp13_;
   double tmp100_ = tmp98_ + tmp99_;
   double tmp101_ = (tmp44_) * tmp17_;
   double tmp102_ = tmp100_ + tmp101_;
   double tmp103_ = (tmp47_) * tmp19_;
   double tmp104_ = tmp102_ + tmp103_;
   double tmp105_ = (tmp47_) * (tmp6_);
   double tmp106_ = (tmp39_) * tmp9_;
   double tmp107_ = tmp105_ + tmp106_;
   double tmp108_ = (tmp107_) * tmp21_;
   double tmp109_ = tmp104_ + tmp108_;
   double tmp110_ = tmp69_ * 2;
   double tmp111_ = (tmp59_) * tmp10_;
   double tmp112_ = (tmp61_) * tmp13_;
   double tmp113_ = tmp111_ + tmp112_;
   double tmp114_ = (tmp64_) * tmp17_;
   double tmp115_ = tmp113_ + tmp114_;
   double tmp116_ = (tmp67_) * tmp19_;
   double tmp117_ = tmp115_ + tmp116_;
   double tmp118_ = (tmp67_) * (tmp16_);
   double tmp119_ = (tmp59_) * tmp22_;
   double tmp120_ = tmp118_ + tmp119_;
   double tmp121_ = (tmp120_) * tmp21_;
   double tmp122_ = tmp117_ + tmp121_;
   double tmp123_ = tmp79_ * 2;
   double tmp124_ = tmp37_ * (tmp36_);
   double tmp125_ = (tmp70_) * tmp10_;
   double tmp126_ = (tmp72_) * tmp13_;
   double tmp127_ = tmp125_ + tmp126_;
   double tmp128_ = (tmp75_) * tmp17_;
   double tmp129_ = tmp127_ + tmp128_;
   double tmp130_ = (tmp78_) * tmp19_;
   double tmp131_ = tmp129_ + tmp130_;
   double tmp132_ = (tmp78_) * (tmp6_);
   double tmp133_ = (tmp70_) * tmp9_;
   double tmp134_ = tmp132_ + tmp133_;
   double tmp135_ = (tmp134_) * tmp21_;
   double tmp136_ = tmp131_ + tmp135_;
   double tmp137_ = tmp38_ * 2;
   double tmp138_ = tmp37_ * (tmp57_);
   double tmp139_ = (tmp80_) * tmp10_;
   double tmp140_ = (tmp82_) * tmp13_;
   double tmp141_ = tmp139_ + tmp140_;
   double tmp142_ = (tmp85_) * tmp17_;
   double tmp143_ = tmp141_ + tmp142_;
   double tmp144_ = (tmp88_) * tmp19_;
   double tmp145_ = tmp143_ + tmp144_;
   double tmp146_ = (tmp88_) * (tmp16_);
   double tmp147_ = (tmp80_) * tmp22_;
   double tmp148_ = tmp146_ + tmp147_;
   double tmp149_ = (tmp148_) * tmp21_;
   double tmp150_ = tmp145_ + tmp149_;
   double tmp151_ = tmp58_ * 2;
   double tmp152_ = tmp95_ - tmp97_;
   double tmp153_ = 2 * tmp5_;
   double tmp154_ = tmp153_ + tmp6_;
   double tmp155_ = 2 * tmp15_;
   double tmp156_ = tmp155_ + tmp16_;

  mVal[0] = (mLocRegDistu1_x + (tmp1_) * (tmp36_) + (tmp91_) * tmp23_ + tmp95_ * tmp24_ + tmp25_ * (tmp1_) + tmp26_ * (tmp3_)) - (mLocRegDistu2_x + (tmp11_) * (tmp57_) + (tmp93_) * tmp23_ + tmp97_ * tmp24_ + tmp25_ * (tmp11_) + tmp26_ * (tmp12_)) - mLocRegDistu3_x;

  mCompDer[0][0] = 0;
  mCompDer[0][1] = (tmp124_ + (tmp109_) * (tmp1_) + ((tmp39_) * 2 + tmp39_) * tmp23_ + tmp110_ * tmp24_ + tmp68_) - (tmp138_ + (tmp122_) * (tmp11_) + ((tmp59_) * 2 + tmp59_) * tmp23_ + tmp123_ * tmp24_ + tmp68_);
  mCompDer[0][2] = ((tmp136_) * (tmp1_) + (tmp70_) * tmp23_ + tmp137_ * tmp24_ + tmp89_) - ((tmp150_) * (tmp11_) + (tmp80_) * tmp23_ + tmp151_ * tmp24_ + tmp89_);
  mCompDer[0][3] = (tmp6_) * (tmp1_) - (tmp16_) * (tmp11_);
  mCompDer[0][4] = tmp7_ * (tmp1_) - tmp18_ * (tmp11_);
  mCompDer[0][5] = tmp8_ * (tmp1_) - tmp20_ * (tmp11_);
  mCompDer[0][6] = tmp9_ * (tmp1_) - tmp22_ * (tmp11_);
  mCompDer[0][7] = tmp34_ * (tmp1_) - tmp55_ * (tmp11_);
  mCompDer[0][8] = (tmp91_) - (tmp93_);
  mCompDer[0][9] = tmp152_;
  mCompDer[0][10] = tmp1_ - (tmp11_);
  mCompDer[0][11] = tmp3_ - (tmp12_);
  mVal[1] = (mLocRegDistu1_y + (tmp3_) * (tmp36_) + (tmp154_) * tmp24_ + tmp95_ * tmp23_) - (mLocRegDistu2_y + (tmp12_) * (tmp57_) + (tmp156_) * tmp24_ + tmp97_ * tmp23_) - mLocRegDistu3_y;

  mCompDer[1][0] = 0;
  mCompDer[1][1] = ((tmp109_) * (tmp3_) + (tmp39_) * tmp24_ + tmp110_ * tmp23_) - ((tmp122_) * (tmp12_) + (tmp59_) * tmp24_ + tmp123_ * tmp23_);
  mCompDer[1][2] = (tmp124_ + (tmp136_) * (tmp3_) + ((tmp70_) * 2 + tmp70_) * tmp24_ + tmp137_ * tmp23_) - (tmp138_ + (tmp150_) * (tmp12_) + ((tmp80_) * 2 + tmp80_) * tmp24_ + tmp151_ * tmp23_);
  mCompDer[1][3] = (tmp6_) * (tmp3_) - (tmp16_) * (tmp12_);
  mCompDer[1][4] = tmp7_ * (tmp3_) - tmp18_ * (tmp12_);
  mCompDer[1][5] = tmp8_ * (tmp3_) - tmp20_ * (tmp12_);
  mCompDer[1][6] = tmp9_ * (tmp3_) - tmp22_ * (tmp12_);
  mCompDer[1][7] = tmp34_ * (tmp3_) - tmp55_ * (tmp12_);
  mCompDer[1][8] = tmp152_;
  mCompDer[1][9] = (tmp154_) - (tmp156_);
  mCompDer[1][10] = 0;
  mCompDer[1][11] = 0;
}


void cREgDistDx_Fraser_PPaEqPPs::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cREgDistDx_Fraser_PPaEqPPs Has no Der Sec");
}

void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu1_x(double aVal){ mLocRegDistu1_x = aVal;}
void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu1_y(double aVal){ mLocRegDistu1_y = aVal;}
void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu2_x(double aVal){ mLocRegDistu2_x = aVal;}
void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu2_y(double aVal){ mLocRegDistu2_y = aVal;}
void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu3_x(double aVal){ mLocRegDistu3_x = aVal;}
void cREgDistDx_Fraser_PPaEqPPs::SetRegDistu3_y(double aVal){ mLocRegDistu3_y = aVal;}



double * cREgDistDx_Fraser_PPaEqPPs::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "RegDistu1_x") return & mLocRegDistu1_x;
   if (aName == "RegDistu1_y") return & mLocRegDistu1_y;
   if (aName == "RegDistu2_x") return & mLocRegDistu2_x;
   if (aName == "RegDistu2_y") return & mLocRegDistu2_y;
   if (aName == "RegDistu3_x") return & mLocRegDistu3_x;
   if (aName == "RegDistu3_y") return & mLocRegDistu3_y;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cREgDistDx_Fraser_PPaEqPPs::mTheAuto("cREgDistDx_Fraser_PPaEqPPs",cREgDistDx_Fraser_PPaEqPPs::Alloc);


cElCompiledFonc *  cREgDistDx_Fraser_PPaEqPPs::Alloc()
{  return new cREgDistDx_Fraser_PPaEqPPs();
}


