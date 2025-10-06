// Can Team A Beat Team B?

#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::any_of;
using std::begin;
using std::end;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

struct MatchResult {
  string winning_team, losing_team;
};

unordered_map<string, unordered_set<string>>
BuildGraph(const vector<MatchResult> &matches) {
  unordered_map<string, unordered_set<string>> graph;
  for (const MatchResult &match : matches) {
    graph[match.winning_team].emplace(match.losing_team);
  }
  return graph;
}

bool IsReachableDFS(const unordered_map<string, unordered_set<string>> &graph,
                    const string &curr, const string &dest,
                    unordered_set<string> &visited) {
  if (curr == dest) {
    return true;
  } else if (visited.find(curr) != visited.end() ||
             graph.find(curr) == graph.end()) {
    return false;
  }
  visited.emplace(curr);
  const auto &team_list = graph.at(curr);
  return any_of(begin(team_list), end(team_list), [&](const string &team) {
    return IsReachableDFS(graph, team, dest, visited);
  });
}

bool CanTeamABeatTeamB(const vector<MatchResult> &matches, const string &team_a,
                       const string &team_b) {
  unordered_set<string> visited;
  return IsReachableDFS(BuildGraph(matches), team_a, team_b, visited);
}
