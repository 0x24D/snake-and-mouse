#if !defined(scoreH)
#define scoreH
class Score{
public:
	Score();
	int getAmount() const;
	void updateAmount(const int& amount);
private:
	int amount_;
};
#endif