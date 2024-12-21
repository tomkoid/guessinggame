project('guessinggame', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

add_project_arguments('-Wall', '-Werror', language : 'cpp')

subdir('src')
exe = executable('guessinggame', sources,
  install : true)

test('basic', exe)
