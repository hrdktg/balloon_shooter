#include <string>

class LoaderParams
{
	public:
		LoaderParams(int x,int y,int w,int h,std::string textureID):m_x(x), m_y(y), m_w(w),m_h(h),m_textureID(textureID) {}

		int getX() const { return m_x; }
		int getY() const { return m_y; }
		int getW() const { return m_w; }
		int getH() const { return m_h; }
		std::string getTextureID() const { return m_textureID; }

	private:
		int m_x,m_y;
		int m_w,m_h;

		std::string m_textureID;
};
