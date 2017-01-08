#if !defined(GridItemH)
#define GridItemH 
class GridItem {
public:
	GridItem(const char& symbol);
	char getSymbol() const;
private:
	const char symbol_;
};
#endif