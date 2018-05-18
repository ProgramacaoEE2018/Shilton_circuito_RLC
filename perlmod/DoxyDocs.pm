$doxydocs=
{
  classes => [
    {
      name => 'Capacitor',
      includes => {
        local => 'no',
        name => 'Classes_cirkt.h'
      },
      all_members => [
        {
          name => 'capacit',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Capacitor'
        },
        {
          name => 'Capacitor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Capacitor'
        },
        {
          name => 'imp',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Capacitor'
        },
        {
          name => 'set_imp',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Capacitor'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Capacitor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'valor',
                type => 'float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'set_imp',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'w',
                type => 'float'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'capacit',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'float'
          },
          {
            kind => 'variable',
            name => 'imp',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'complex< double >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Indutor',
      includes => {
        local => 'no',
        name => 'Classes_cirkt.h'
      },
      all_members => [
        {
          name => 'imp',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Indutor'
        },
        {
          name => 'indut',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Indutor'
        },
        {
          name => 'Indutor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Indutor'
        },
        {
          name => 'set_imp',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Indutor'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Indutor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'valor',
                type => 'float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'set_imp',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'w',
                type => 'float'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'indut',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'float'
          },
          {
            kind => 'variable',
            name => 'imp',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'complex< double >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Resistor',
      includes => {
        local => 'no',
        name => 'Classes_cirkt.h'
      },
      all_members => [
        {
          name => 'imp',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Resistor'
        },
        {
          name => 'resist',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Resistor'
        },
        {
          name => 'Resistor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Resistor'
        },
        {
          name => 'set_imp',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Resistor'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Resistor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'valor',
                type => 'float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'set_imp',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'w',
                type => 'float'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'resist',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'float'
          },
          {
            kind => 'variable',
            name => 'imp',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'complex< double >'
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  namespaces => [
    {
      name => 'std',
      classes => [
      ],
      namespaces => [
      ],
      brief => {},
      detailed => {}
    }
  ],
  files => [
    {
      name => 'Classes_cirkt.h',
      includes => [
        {
          name => 'complex'
        }
      ],
      included_by => [
        {
          name => 'Project5/Origem.cpp',
          ref => '_origem_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Origem.cpp',
      includes => [
        {
          name => 'iostream'
        },
        {
          name => 'complex'
        },
        {
          name => 'vector'
        },
        {
          name => 'Classes_cirkt.h',
          ref => '_classes__cirkt_8h'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  groups => [
  ],
  pages => [
  ]
};
1;
