double frp[5] = {e, d, c, b, a};	//	quartic constant C as Cx^i
std::complex<double> quart;	//	store result of quartic line
template <typename T> double sgn(T v) {return (0. < v) - (v < 0.);}	//	typesafe sgn for real numbers
for(double s = -1; s <= 1; s = s + 2) for(double t = -1; t <= 1; t = t + 2) {
  //	make fully complex safe by removing .real() and changing cbrt(x) to pow(x,1./3) but it will have less precision (see x=343 with std::cout.precision(std::numeric_limits<double>::max_digits10);)
  quart = (-3.*frp[3]+s*(std::sqrt(complex<double>(
    3.*(3.*std::pow(frp[3],2.)-8.*frp[4]*frp[2]+2.*frp[4]*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]+std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real())+2.*frp[4]*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]-std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real()))
  ))
  +t*std::sqrt(
    3.*(3.*std::pow(frp[3],2.)-

    8.*frp[4]*frp[2]+2.*frp[4]*(-1.+std::sqrt(complex<double>(-3.)))/2.*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]+std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real())

    +

    2.*frp[4]*(-1.+-1.*std::sqrt(complex<double>(-3.)))/2.*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]-std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real())

    )
  ))+t*sgn((sgn(-std::pow(frp[3],3.)+4.*frp[4]*frp[3]*frp[2]-8.*std::pow(frp[4],2.)*frp[1])-1./2.)*(sgn(std::max(std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.),std::min(3.*std::pow(frp[3],2.)-8.*frp[4]*frp[2],3.*std::pow(frp[3],4.)+16.*std::pow(frp[4],2.)*std::pow(frp[2],2.)+16.*std::pow(frp[4],2.)*frp[3]*frp[1]-16.*frp[4]*std::pow(frp[3],2.)*frp[2]-64.*std::pow(frp[4],3.)*frp[0])))-1./2.))*std::sqrt(
    3.*(3.*std::pow(frp[3],2.)-8.*frp[4]*frp[2]+

    2.*frp[4]*(-1.+-1.*std::sqrt(complex<double>(-3.)))/2.*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]+std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real())

    +

    2.*frp[4]*(-1.+std::sqrt(complex<double>(-3.)))/2.*std::cbrt(4.*(2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]-std::sqrt(complex<double>(
      std::pow((2.*std::pow(frp[2],3.)-9.*frp[3]*frp[2]*frp[1]+27.*frp[4]*std::pow(frp[1],2.)+27.*std::pow(frp[3],2.)*frp[0]-72.*frp[4]*frp[2]*frp[0]),2.)-4.*std::pow((std::pow(frp[2],2.)-3.*frp[3]*frp[1]+12.*frp[4]*frp[0]),3.)
    ))).real())

    )
  ))/(12.*frp[4]);
  std::cout << "s=" << s << ", t=" << t << ":\t" << quart.real() << "+" << quart.imag() << "i" << std::endl;	//	output each element
}
