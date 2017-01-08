#include "GridItem.h"
GridItem::GridItem(const char& symbol) : symbol_(symbol) {}
char GridItem::getSymbol() const {
	return symbol_;
}