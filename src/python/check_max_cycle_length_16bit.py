# So used the best intial configuration given a rule 
import numpy as np
from itertools import product

rules=[]
config=[]
lengths=[]

def run_sim(example_input):
  def eca_step(config, rule, rule_vector):
      """Compute the next configuration of the ECA given the current configuration and rule vector."""
      n = len(config)
      new_config = np.zeros(n, dtype=int)

      for i in range(n):
          left = config[i-1] if i > 0 else 0
          center = config[i]
          right = config[i+1] if i < n-1 else 0
          neighborhood = 4*left + 2*center + 1*right
          new_config[i] = rule[rule_vector[i]][neighborhood]

      return tuple(new_config)

  def find_cycles(n, rule, rule_vector):
      """Find all cycles and return the initial configuration with the largest cycle length."""
      visited = {}
      all_configs = list(product([0, 1], repeat=n))
      left_out_configs = set(all_configs)
      max_cycle_length = 0
      best_initial_config = None

      while left_out_configs:
          initial_config = left_out_configs.pop()
          current_config = initial_config
          cycle = []
          config_index = {}

          while current_config not in visited:
              visited[current_config] = len(cycle)
              config_index[current_config] = len(cycle)
              cycle.append(current_config)
              current_config = eca_step(current_config, rule, rule_vector)

              if current_config in left_out_configs:
                  left_out_configs.remove(current_config)

          if current_config in config_index:
              cycle_start = config_index[current_config]
              cycle_length = len(cycle) - cycle_start

              if cycle_length > max_cycle_length:
                  max_cycle_length = cycle_length
                  best_initial_config = initial_config

      return best_initial_config, max_cycle_length

  def main():
      n = 16  # lattice size
      rule_vector = example_input  # example rule vector
      rule_set = {
          5: [int(x) for x in f'{5:08b}'[::-1]],
          6: [int(x) for x in f'{6:08b}'[::-1]],
          9: [int(x) for x in f'{9:08b}'[::-1]],
          10: [int(x) for x in f'{10:08b}'[::-1]],
          15: [int(x) for x in f'{15:08b}'[::-1]],
          20: [int(x) for x in f'{20:08b}'[::-1]],
          23: [int(x) for x in f'{23:08b}'[::-1]],
          27: [int(x) for x in f'{27:08b}'[::-1]],
          30: [int(x) for x in f'{30:08b}'[::-1]],
          39: [int(x) for x in f'{39:08b}'[::-1]],
          43: [int(x) for x in f'{43:08b}'[::-1]],
          45: [int(x) for x in f'{45:08b}'[::-1]],
          51: [int(x) for x in f'{51:08b}'[::-1]],
          53: [int(x) for x in f'{53:08b}'[::-1]],
          54: [int(x) for x in f'{54:08b}'[::-1]],
          57: [int(x) for x in f'{57:08b}'[::-1]],
          58: [int(x) for x in f'{58:08b}'[::-1]],
          60: [int(x) for x in f'{60:08b}'[::-1]],
          62: [int(x) for x in f'{62:08b}'[::-1]],
          65: [int(x) for x in f'{65:08b}'[::-1]],
          73: [int(x) for x in f'{73:08b}'[::-1]],
          75: [int(x) for x in f'{75:08b}'[::-1]],
          77: [int(x) for x in f'{77:08b}'[::-1]],
          78: [int(x) for x in f'{78:08b}'[::-1]],
          80: [int(x) for x in f'{80:08b}'[::-1]],
          83: [int(x) for x in f'{83:08b}'[::-1]],
          85: [int(x) for x in f'{85:08b}'[::-1]],
          86: [int(x) for x in f'{86:08b}'[::-1]],
          89: [int(x) for x in f'{89:08b}'[::-1]],
          90: [int(x) for x in f'{90:08b}'[::-1]],
          92: [int(x) for x in f'{92:08b}'[::-1]],
          99: [int(x) for x in f'{99:08b}'[::-1]],
          101: [int(x) for x in f'{101:08b}'[::-1]],
          102: [int(x) for x in f'{102:08b}'[::-1]],
          105: [int(x) for x in f'{105:08b}'[::-1]],
          106: [int(x) for x in f'{106:08b}'[::-1]],
          108: [int(x) for x in f'{108:08b}'[::-1]],
          110: [int(x) for x in f'{110:08b}'[::-1]],
          113: [int(x) for x in f'{113:08b}'[::-1]],
          114: [int(x) for x in f'{114:08b}'[::-1]],
          120: [int(x) for x in f'{120:08b}'[::-1]],
          135: [int(x) for x in f'{135:08b}'[::-1]],
          141: [int(x) for x in f'{141:08b}'[::-1]],
          142: [int(x) for x in f'{142:08b}'[::-1]],
          147: [int(x) for x in f'{147:08b}'[::-1]],
          149: [int(x) for x in f'{149:08b}'[::-1]],
          150: [int(x) for x in f'{150:08b}'[::-1]],
          153: [int(x) for x in f'{153:08b}'[::-1]],
          154: [int(x) for x in f'{154:08b}'[::-1]],
          156: [int(x) for x in f'{156:08b}'[::-1]],
          163: [int(x) for x in f'{163:08b}'[::-1]],
          165: [int(x) for x in f'{165:08b}'[::-1]],
          166: [int(x) for x in f'{166:08b}'[::-1]],
          169: [int(x) for x in f'{169:08b}'[::-1]],
          170: [int(x) for x in f'{170:08b}'[::-1]],
          172: [int(x) for x in f'{172:08b}'[::-1]],
          177: [int(x) for x in f'{177:08b}'[::-1]],
          178: [int(x) for x in f'{178:08b}'[::-1]],
          180: [int(x) for x in f'{180:08b}'[::-1]],
          195: [int(x) for x in f'{195:08b}'[::-1]],
          198: [int(x) for x in f'{198:08b}'[::-1]],
          197: [int(x) for x in f'{197:08b}'[::-1]],
          201: [int(x) for x in f'{201:08b}'[::-1]],
          202: [int(x) for x in f'{202:08b}'[::-1]],
          204: [int(x) for x in f'{204:08b}'[::-1]],
          210: [int(x) for x in f'{210:08b}'[::-1]],
          212: [int(x) for x in f'{212:08b}'[::-1]],
          216: [int(x) for x in f'{216:08b}'[::-1]],
          225: [int(x) for x in f'{225:08b}'[::-1]],
          228: [int(x) for x in f'{228:08b}'[::-1]],
          232: [int(x) for x in f'{232:08b}'[::-1]],
          240: [int(x) for x in f'{240:08b}'[::-1]],

          # add more rules as needed
      }

      best_config, max_length = find_cycles(n, rule_set, rule_vector)


      print("Best Initial Configuration:", best_config)
      print("Maximum Cycle Length:", max_length)
      print("Rule Vector: ",rule_vector)
      rules.append(rule_vector)
      config.append(best_config)
      lengths.append(max_length)

  if __name__ == "__main__":
      main()
input=[[6, 165, 169, 165, 106, 90, 169, 165, 106, 90, 169, 165, 106, 90, 90, 5]]
for i in input:
  run_sim(i)

print(rules)
print(config)
print(lengths)