nginx_setup:
  pkg.installed:
    - pkgs:
      - nginx
      - git
      - zsh
