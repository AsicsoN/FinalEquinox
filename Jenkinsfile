pipeline {
  agent node
  stages {
    stage('Build Unreal') {
      steps {
        powershell 'build.ps1'
      }
    }
  }
}