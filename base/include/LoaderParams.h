#ifndef LOADERPARAMS_H_
#define LOADERPARAMS_H_
#include <string>
#include "Vector2d.h"
#include "TextureManager.h"

class LoaderParams
{
	public:
		LoaderParams(std::string textureID, int x,int y,int w,int h):m_textureID(textureID), m_x(x), m_y(y), m_w(w),m_h(h),isAnim(false),isScaled(false)
		{}
		LoaderParams(std::string textureID, int x,int y,bool=false); // For isAnim
		LoaderParams(std::string textureID, int x,int y,int sw,int sh,int dw,int dh); // For scalable
		
		int getX() const { return m_x; }
		int getY() const { return m_y; }
		int getW() const { return m_w; }
		int getH() const { return m_h; }
		std::string getTextureID() const { return m_textureID; }

		int getDW() const { return m_dw; }
		int getDH() const { return m_dh; }
		bool isAnimObj() const { return isAnim; }
		bool isScaledObj() const { return isScaled; }
	
	private:
		int m_x, m_y;
		int m_w, m_h;
		int m_dw,m_dh;
		std::string m_textureID;
		bool isAnim, isScaled;
};
#endif