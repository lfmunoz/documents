

bool compare_names(string a, string b) {
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  return a < b;
}

bool theTruthIsOutThere(const racer &a, const racer &b) {
  if (a.min == b.min) {
    if (a.sec == b.sec) {
      if (a.ms == b.ms)
        return compare_names(a.name, b.name);
      else
        return a.ms < b.ms;
    }

    return a.sec < b.sec;
  }

  return a.min < b.min;
}

sort(racers.begin(), racers.end(), theTruthIsOutThere);




	bool operator < (const Record& r2) const {
		if (score == r2.score) {
			string s1 = toLower(name);
            string s2 = toLower(r2.name);
			return s1 < s2;
		}
		return score < r2.score;
	}